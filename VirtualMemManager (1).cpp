#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

#define FRAME_SIZE 256        // size of the frame
#define TOTAL_NUMBER_OF_FRAMES 256  // total number of frames in physical memory
#define ADDRESS_MASK  0xFFFF  //mask all but the address
#define OFFSET_MASK  0xFF //mask all but the offset
#define TLB_SIZE 16       // size of the TLB
#define PAGE_TABLE_SIZE 256  // size of the page table
#define BUFFER_SIZE 10 // number of characters to read for each line from input file
#define CHUNK 256 // number of bytes to read

class VirtualMemoryManager {
    private:
        struct PageFrame {
            int pageNumber;
            int frameNumber;
        };
        const char *address_file_str;
        const char *backingStore_txt;
        signed char buffer[BUFFER_SIZE];
        int physicalMemory[TOTAL_NUMBER_OF_FRAMES][FRAME_SIZE];
        int TLBHits, pageFaults, firstAvailableFrame, firstAvailablePageTblNo, noOfTlbEntries;
        // Declaration of twin arrays
        PageFrame TLB[TLB_SIZE];
        PageFrame PAGE_TABLE[PAGE_TABLE_SIZE];
        FILE *backingStore, *outputFile;

        void getPage(int logicalAddress) {
            int pageNumber = (logicalAddress & ADDRESS_MASK) >> 8;
            int offset = logicalAddress & OFFSET_MASK;
            int frameNumber = -1, value;
            for(int i = 0; i < TLB_SIZE; i++) {
                if(TLB[i].pageNumber == pageNumber) {
                    frameNumber = TLB[i].frameNumber;
                    TLBHits++;
                }
            }
            // Look through the page Table if not found in the TLB
            if(frameNumber == -1) {
                for(int i = 0; i < firstAvailablePageTblNo; i++) {
                    if(PAGE_TABLE[i].pageNumber == pageNumber) {
                        frameNumber = PAGE_TABLE[i].frameNumber;
                    }
                }
            }
            if(frameNumber == -1) {
                frameNumber = readFromBackingStore(pageNumber);
                pageFaults++;
            }
            insertIntoTLB(pageNumber, frameNumber);
            writeToOuput(logicalAddress, frameNumber);
        }

        int readFromBackingStore(int pageNumber) {
            if(fseek(backingStore, pageNumber * CHUNK, SEEK_SET) != 0) {
                cerr << "Error seeking from the Backing_Store.bin\n";
            }
            if(fread(buffer, sizeof(signed char), CHUNK, backingStore) == 0) {
                cerr << "Error reading from the Backing_Store.bin\n";
            }
            // Load the bits into the first available frame in the physical memory
            for(int i = 0; i < CHUNK; i++) {
                physicalMemory[firstAvailableFrame][i] = buffer[i];
            }
            PAGE_TABLE[firstAvailablePageTblNo].pageNumber = pageNumber;
            PAGE_TABLE[firstAvailablePageTblNo].frameNumber = firstAvailableFrame;
            ++firstAvailableFrame;
            ++firstAvailablePageTblNo;
            return PAGE_TABLE[firstAvailablePageTblNo-1].frameNumber;
        }

        void writeToOuput(int logicalAddress, int frameNumber) {
            int offset = logicalAddress & OFFSET_MASK;
            char value = physicalMemory[frameNumber][offset];
            int physicalAddress = (frameNumber << 8) | offset;
            outputFile = fopen("Output.txt", "a");
            fprintf(outputFile, "Virtual address: %d Physical address: %d Value: %d\n"
                ,logicalAddress, physicalAddress, value);
            fclose(outputFile);
        }

        void insertIntoTLB(int pageNumber, int frameNumber) {
            int i;
            for(i = 0; i < noOfTlbEntries; i++){
                if(TLB[i].pageNumber == pageNumber) {
                    for(; i < noOfTlbEntries - 1; i++) {
                        TLB[i] = TLB[i + 1];
                    }
                    break;
                }
            }
            // Shift everything int the TLB one over to the left
            if(i == noOfTlbEntries){
                for (int j = 0; j < i; j++)
                    TLB[j] = TLB[j + 1];

            }
            TLB[i].pageNumber = pageNumber;
            TLB[i].frameNumber = frameNumber;

            if(noOfTlbEntries < TLB_SIZE - 1) {
                noOfTlbEntries++;
            }
        }

    public:
        VirtualMemoryManager(const char *file)
            : address_file_str(file), backingStore_txt("BACKING_STORE.bin") {
            pageFaults = TLBHits =  firstAvailableFrame = firstAvailablePageTblNo =
                noOfTlbEntries = 0;
            backingStore = fopen(backingStore_txt, "rb");
        }

        // Translates Virtual Addresses into Physical Addresses
        void translate();
};

void VirtualMemoryManager::translate() {
    FILE *address_file = fopen(address_file_str, "r");
    if(address_file == NULL) {
        cerr << "Error opening " << address_file_str;
        return;
    }
    int logicalAddress; char address[BUFFER_SIZE];
    while(fgets(address, BUFFER_SIZE, address_file) != NULL) {
        logicalAddress = atoi(address);
        getPage(logicalAddress);
    }
    outputFile = fopen("Output.txt", "a");
    fprintf(outputFile, "Page Faults = %d\nTLB Hits = %d", pageFaults, TLBHits);
    fclose(backingStore);
    fclose(outputFile);
    fclose(address_file);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cerr << "Usage: ./a.out [input file]\n";
        return 1;
    }

    VirtualMemoryManager virtualMemoryManager(argv[1]);
    virtualMemoryManager.translate();
    return 0;
}