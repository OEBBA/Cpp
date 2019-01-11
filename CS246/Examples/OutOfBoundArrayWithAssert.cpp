#include <iostream>
#include <cassert>
int main()
          {
              using namespace std;
              int a[10] = {0,1,2,3,4,5,6,7,8,9}, i;
for(i=0; i<10; i++)
{ assert(i+1 < 10);//assert condition
a[i] = a[i+1]; //for this assignment }
              //print out values
              cout << "myarray elements ";
              for(int i=0;i<10;i++)
                 cout << ' ' << a[i];
              cout << "\n";
              return 0;
}
