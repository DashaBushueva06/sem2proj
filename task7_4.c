#include <stdio.h>

#define N5

int input_array(int ar[N]){
    for(int i=0; i<M;i++){
        printf("Input ar[%d]=",i);
        int ch = scanf("%d",&ar[i]);
        if (ch != 1) return i;
    }
    return N;
}

int max_array(int ar[],int n){
    int maximum = ar[0];
    for(int i=1;i<n;i++){
        if(maximum<ar[i]){
            maximum=ar[i];
        }
    return maximum    
    }
}

void task4(){
    int mas[N];
    int k = input_array(mas);
    int maximum = max_array(mas,k);
    printf("maximum =%d",maximum);
}
