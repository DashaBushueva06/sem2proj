#include <stdio.h>

int main() {
    int x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 5;
    double y1 = 3.0, y2 = 1.0, y3 = 5.0, y4 = 4.0, y5 = 2.1;

    printf("x | %d  | %d  | %d  | %d  | %d  |\n", x1, x2, x3, x4, x5);
    printf("- | -- | -- | -- | -- | -- |\n");
    printf("y | %.1f | %.1f | %.1f | %.1f | %.1f |\n", y1, y2, y3, y4, y5);

    return 0;
}