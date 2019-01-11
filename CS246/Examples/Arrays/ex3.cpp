//This program creates an increasing half pyramid

#include <iostream>
#include <string>
using namespace std;


int main(){

int n;

cout<<"Enter a Number of rows"<<endl;
cin>>n;

for(int i=1; i<n; i++)
{
  for(int j=1; j<i; j++){
    cout<<"*";
    }
    cout<<endl;
  }
  return 0;
}
