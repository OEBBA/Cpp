#include "clock.h"
#include <iostream>

using namespace std;

int main(){

clock c;

c.setClock(2,30,false);
cout<< "Time is: " << endl;
cout<<c.gethour() << ":" <<c.getminute() <<endl;

if (c.noonOrmidnight())
cout<<"AM"<<endl;

else
cout<<"PM"<<endl;

}
