#include <stdio.h>

float celsiusToFahrenheit(float temp);

int main() {
    printf("Celsius\tFarenheit\n");
    for (int celsius = 300; celsius >= 0; celsius -= 20) {
        float farenheit = celsiusToFahrenheit(celsius);
        printf("%7d\t%9.2f\n", celsius, farenheit);
    }
    return 0;
}

float celsiusToFahrenheit(float temp) {
    return temp * (9.0 / 5.0) + 32.0;
}