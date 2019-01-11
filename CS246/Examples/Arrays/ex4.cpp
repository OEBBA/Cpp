#include <iostream>
#include <string>

using namespace std;

int n;

int main(){
cout<<"Enter a number"<<endl;
cin>>n;

  for (int i=0; i<n; i++){
    for (int j=10; j>i; j--){

      cout<<"*";

      }
      cout<<endl;
    }
return 0;
}
