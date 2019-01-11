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
