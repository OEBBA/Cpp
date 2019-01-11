#include "bag.h"

bag::bag(){

currentSize = -1;

}

void bag::insert(int newEntry){

if(currentSize<100){

currentSize++;

container[currentSize] = newEntry;

}

}

int bag::erase(int newEntry){

bool found=false;

int index;

for(int i=0;i<=currentSize;i++){

if(container[i]==newEntry){

found = true;

index = i;

break;

}

}

if(found){

for(int i=index;i<currentSize;i++){

container[i]= container[i+1];

}

}

if(found){

currentSize--;

return newEntry;

}else{

return -9999;

}

}

bool bag::erase_one(int newEntry){

bool found=false;

for(int i=0;i<=currentSize;i++){

if(container[i]==newEntry){

found = true;

for(int j=i;j<currentSize;j++){

container[j]= container[j+1];

}

i--;

currentSize--;

}

}

return found;

}

void bag::display(){

for(int i=0;i<=currentSize;i++){

cout<<container[i]<<" ";

}

cout<<endl;

}

int bag::size()const{

return currentSize+1;

}

int bag::count(int target)const{

int count=0;

for(int i=0;i<=currentSize;i++){

if(container[i]==target){

count++;

}

}

cout<<"Number "<<target<<" found "<<count<<" times"<<endl;

return count;

}

int main(){

bag b;

b.insert(1);

b.insert(3);

b.insert(3);

b.insert(10);

b.insert(9);

b.insert(3);

b.insert(18);

b.insert(1);

cout<<"Displaying bag content "<<endl;

b.display();

cout<<"Erasing 9 from bag"<<endl;

b.erase(9);

b.display();

cout<<"Erasing all 3 from bag"<<endl;

b.erase_one(3);

b.display();

b.count(1);

cout<<"Bag size is : "<<b.size();

return 0;

}
