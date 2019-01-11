//This program prints the odd numbers in a 2D array
#include <iostream>
#include <string>
using namespace std;

int arr[2][5]={{10,20,9,18,12},{22,16,14,7,13}};
int n;

int main(){

    cout<< "Odd Numbers: " << endl;
    for(int row=0; row<2; row++){
        for(int col=0; col<5; col++){
            if(arr[row][col]%2!=0)
            n=arr[row][col];
            }
            cout<<n<<endl;
        }
        return 0;
}
