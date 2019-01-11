#include "point.h"
#include <iostream>

using namespace std;
double x;
double y;
double a;
double b;
double result;

int main(){
result = distanceBetweenTwoPoints(x, y, a, b);
}
double distanceBetweenTwoPoints(double x, double y, double a, double b){
return sqrt(pow(x - a, 2) + pow(y - b, 2));

}
