//Prints Max Number in a 2D Array
#include <iostream>
#include <string>
using namespace std;

int arr[2][5] ={{40,7,12,3,0},{10,2,30,9,8}};
int temp=0;

int main()
{
    for(int row=0; row<2; row++){
        for(int col=0; col<5; col++){
            if(arr[row][col]>temp)
            temp = arr[row][col];
            }

        }
        cout<<temp;
        return 0;
}
