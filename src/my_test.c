#include "s21_string.h"

int main(void) {
    float a = 0., b = 0., c = 0., d = 0.;
    int result = s21_sscanf("30.402823466E+38", "%E", &a);
    int result_origin = sscanf("30.402823466E+38", "%E", &c);
    printf("%d %d\n", result, result_origin);
    return 0;
}