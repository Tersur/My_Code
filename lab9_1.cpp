//lab9_1.cpp by Basil Gaji
#include<iostream>
#include<cmath>
#include <iomanip>
#define PI 3.141592
using namespace std;

void calc_angle(double a, double &b, double &c);
int main(){
    double angle, sin_val, cos_val;

    cout.precision(4);
    cout<<"Please enter the angle theta you want to calculate sin and cos for: ";
    cin>>angle;
    calc_angle(angle, sin_val, cos_val);
    cout<<"The sin of "<<angle<<" degrees is "<<sin_val<<endl;
    cout<<"The cos of "<<angle<<" degrees is "<<cos_val<<endl;

    return 1;
}

void calc_angle(double a, double &b, double &c){
    b = sin(a*PI/180);
    c =cos(a*PI/180);

}