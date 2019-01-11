#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(string word){
int wordSize = word.size()

stack<char>s;
for(int i=0; i<wordSize/2; i++){
  s.push(word[0]);
  word.erase(0,1);
}

if(word.size()>s.size()){
  word.erase(0,1)
}

if(s.size() == 0){
  return true;
}

while(s.size() > 0){

  if(s.top() == word[0]){
    s.pop();
    word.erase(0,1);

  if(s.size() == 0|| word.size()==0){
    return true;
      }

    }
    else {
      return false;
    }
  }
}
