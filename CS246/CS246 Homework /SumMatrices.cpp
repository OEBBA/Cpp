//This Program Sums Matrices
#include <iostream>
#include <string>
using namespace std;

int row=2, col=3;

int A[2][3]={{10,15,90},{8,23,88}};
int B[2][3]={{17,21,22},{5,13,28}};
int C[2][3];

int main(){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            C[i][j]=A[i][j]+B[i][j];
            }
        }

  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
    cout<<C[i][j]<<" ";
        }
        cout<<end;
    }
    return 0;
}
