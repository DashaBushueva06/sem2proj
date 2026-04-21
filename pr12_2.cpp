#include<iostream>
#include<cstdlib>

int main(){
    char str[10];
    unsigned long long x,y;
    y = 0;
    while(std::cin.get(str,10)){
        x=atoll(str);
        y+= x;
    }
    std::cout<<"y="<<y<<std::endl;
}
