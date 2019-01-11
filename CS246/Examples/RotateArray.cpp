//Given an array, this program rotates the array to the right by k steps, where k is non- negative.

#include <iostream>
#include <string>

using namespace std;

int a[7]={1,2,3,4,5,6,7};
int b[7];
int n=7;
int k;

int main(){
    cout<<"Enter a number of steps to rotate ";
    cin>>k;

      for(int i=0;i<n; i++){
          b[(i+k)%n]=a[i];
          }

      for(int i=0; i<n; i++){
          cout<<b[i]<<" "<<;
          }

  return 0;
}
