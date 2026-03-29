#include <stdio.h>

struct Field {
    char vert;
    unsigned char hor;
};

void print_Field(struct Field x) {
    printf("%c %hhu", x.vert, x.hor);
}

struct Field input_Field() {
    struct Field f;
    printf("Input chess field: ");
    scanf("%c %hhu", &f.vert, &f.hor);
    return f;
}

int main() {
    struct Field y;
    y = input_Field();
    print_Field(y);
}