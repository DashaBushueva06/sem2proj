#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int main(){
    int n;
    cout<<"n=";
    cin>>n;
    int*m=new int[n];
    for(int i=0;i<n;i++){
        cout<<"m["<<i<<"]=";
        cin>>m[i];
    }
    double* x = new double[n];
    char fname[] = "pr9.txt";
fstream f;
f.open(fname);
    if (f.bad()){
       cerr<<"File"<<fname<<"is not proud()"<<f.bad();
        return -1;
    }
    for(int i=0;i<n;i++){
        if(f>>x[i]){}
        else {break;}
    }
    f.close();
    char fz[]="z.txt";
    fstream g;
    g.open(fz);
    for(int i=0;i<n;i++){
    double z = pow(x[i],m[i]);
    g<<z<<" ";
    }
    g.close();
    delete[]m;
    delete[]x;
}

