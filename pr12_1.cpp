#include<iostream>
#include<cmath>

using namespace std;
int main(){
    double x,y,z;
    cout<<"Input x,y";
    cin>>x>>y;
    z = pow(x,y);
    cout<<"z="<<z<<scientific<<z<<"/n";
}