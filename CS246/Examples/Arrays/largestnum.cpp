//This Program prints the largets number in a 2Darray

#include <iostream>
#include <string>

using namespace std;

int arr[2][3]={{1,2,3,},{4,8,6}};
int n;

int main(){
    for(int row=0; row<2; row++){
        for(int col=0; col<3; col++){
            if(n<arr[row][col])
            n=arr[row][col];
            }
        }
    cout<<n;
  return 0;
}
