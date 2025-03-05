#include <stdio.h>
#include <math.h>

#define WIDTH 40
#define HEIGHT 40
#define EXIT_SUCCESS 0

int main() {
    float w = WIDTH;
    float h = HEIGHT;

    for (int col = 0; col < HEIGHT; ++col) {
        for (int row = 0; row < WIDTH; ++row) {
            float x = col;
            float y = row;
            float cx = (2*x-w)/h;
            float cy = (2*y-h)/h;
            float d = sqrt(cx*cx + cy*cy);;
            d -= 0.5;
            d += 0.01*h/(2*(x - y) + h - w);
            d = fabsf(d);
            d = 0.1/d;
            char c = " -+=<@#"[(int)floorf(d/(1 + d)*7)];
            printf("%c%c", c, c);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}








