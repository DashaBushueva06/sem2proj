#include<iostream>
#include<cmath>

using namespace std;
int main(){
    unsigned n;
    cout<<"n=";
    cin>>n;
    for(unsigned i=1;i<=n;i++){
        cout.width(7);
        cout<<i;
    }
    cout<<"\n";
    for(unsigned i=1;i<=n;i++){
        cout.width(7);
        cout.precision(3);
        cout<<sqrt(i);
    }
}