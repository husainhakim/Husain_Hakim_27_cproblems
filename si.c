#include <stdio.h>

int main() {
    float p, r, t, si;
    
    printf("Enter principal amount:-");
    scanf("%f", &p);

    printf("Enter annual interest rate:-");
    scanf("%f", &r);
    
    printf("Enter time in years:-");
    scanf("%f", &t);
    
    si = (p * r * t) / 100.0;
    
    printf("Simple Interest:-%.2f\n", si);
    
    return 0;
}
