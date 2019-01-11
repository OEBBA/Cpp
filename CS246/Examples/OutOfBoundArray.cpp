//Demonstrating example program for array
//out-of-bound assignment
#include <iostream>

int main(){
using namespace std;
int a[10]={0,1,2,3,4,5,6,7,8,9};

//modify the values
for (int i=0; i<10; i++)
a[i] = a[i+1]; //a[9]
}
