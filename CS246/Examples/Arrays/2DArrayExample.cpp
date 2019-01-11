#include <iostream>
using namespace std;

int main(){

int grades[5][3]=
//5 students, 3 grades each.
{{78,83,81},
 {90,88,94},
 {71,73,78},
 {97,96,95},
 {89,93,90}
}

//Average overall of 2D array(Exercise)
int sum =0;
for(int r=0; r<rows; r++)
 for(int c=0; c<cols;c++)
  sum=sum+grades[r][c];

  int avg=sum/(rows*cols);

  //Function that prints the elements of a 2d array as they appear in the matrix(Exercise)
void printArray(int matrix[][]){
  for(int i=0; i<matrix.length; i++){
    for(int j=0; j<matrix[0].length; j++)
    cout<<(matrix[i][j])<<"");
    cout<<endl;
    }
  }
  return 0;
};
