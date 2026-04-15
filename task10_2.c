#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 

struct Field{
    char vert;     
    unsigned char hor;
};

int can_queen_move(struct Field start, struct Field end){
    if (start.vert == end.vert && start.hor == end.hor){
        return false;
    }
    int d_vert = abs(start.vert - end.vert); 
    int d_hor = abs(start.hor - end.hor);   
    if (start.vert == end.vert || start.hor == end.hor || d_vert == d_hor){
        return true;
    }
    return false;
}

struct Field input_Field(){
    struct Field f;
    printf("Input chess field (e.g., a 5): ");
    scanf(" %c %hhu", &f.vert, &f.hor);
    return f;
}

int main(){
    struct Field f1, f2;
    printf("Start field:\n");
    f1 = input_Field();
    printf("End field:\n");
    f2 = input_Field();
    if (can_queen_move(f1, f2)) {
        printf("Queen can move from %c%hhu to %c%hhu\n", f1.vert, f1.hor, f2.vert, f2.hor);
    } else {
        printf("Queen cannot move there in one step\n");
    }
}