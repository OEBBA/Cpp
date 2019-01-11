//TwoSum problem. Takes a target number
//and prints the indices of numbers whose values adds
//up to the target number.

#include <iostream>
#include <string>

using namespace std;

int arr[4]={2,7,11,15};
int x;

int main(){
    cout<<"Enter a target number ";
    cin>>x;

    for(int i=0; i<4; i++){
        for(int j=i+1; j<4; j++){

        if(arr[i]+arr[j]==x)
        cout<<i<<" "<<j;

            }
        }

  return 0;
}
