#include <stdio.h>

int main() {
    for (int f = 0; f <= 300; f += 20) {
        float celsius = (5.0 / 9.0) * (f - 32.0);
        printf("%3d\t%6.2f\n", f, celsius);
    }
    return 0;
}