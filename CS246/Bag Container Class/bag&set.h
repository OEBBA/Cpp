#include <iostream>
using namesapce std;

class bag{
public:

  bag();//places bag in the initial, empty state

  //modification member functions
  void insert (int new_entry); //inserts new number in the bag
  int erase(int target); //removes on copy of a number from the bag
  bool erase_one(int target); //removes all copy of an umber from the bag

 // constant member functions
  int size()const; //counts how many numbers are in the bag
  int count(int target) const; //counts how many copies of a number occur in the bag

private:
};

class set: protected bag
{
public:


int printUnion(int arr1[], int arr2[], int m, int n)

{

int i = 0, j = 0;

while(i < m && j < n)

{

if(arr1[i] < arr2[j])

cout<<arr1[i++]<<" ";

else if(arr2[j] < arr1[i])

cout<<arr2[j++]<<" ";

else

{

cout<<arr2[j++]<<" ";

i++;

}

}


while(i < m)

cout<<arr1[i++]<<" ";

while(j < n)

cout<<arr2[j++]<<" ";

}

int printIntersection(int arr1[], int arr2[], int m, int n)

{

int i = 0, j = 0;

while(i < m && j < n)

{

if(arr1[i] < arr2[j])

i++;

else if(arr2[j] < arr1[i])

j++;

else /* if arr1[i] == arr2[j] */

{

cout<<arr2[j++]<<" ";

i++;

}

}

}

};
