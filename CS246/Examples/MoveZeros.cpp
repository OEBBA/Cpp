//Move zeroes in an array to end of array
#include <iostream>
#include <string>

int arr[5]={0,1,0,3,12};
int i=0;
int j=0;

int main(){
for(i; i<5; i++){ //For loop to print non zeroes
  if(arr[i]!=0)
  arr[j++]=arr[i];
  cout<<arr[i];

  }
for(j; j<5; j++){
  if(arr[j]=0)
  cout<<arr[j];

}

  return 0;
}
