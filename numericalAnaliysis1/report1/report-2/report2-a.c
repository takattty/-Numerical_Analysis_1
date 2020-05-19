#include <stdio.h>
#include <math.h>

#define EPSILON 1.e-15

double func(double);
double dfunc(double);

int main(void)
{
    double a = 1. ;
    printf("Initial value a = %f\n", a);
    int i = 1;
    double b;

    while(1) {
        b = a - func(a) / dfunc(a);
        printf("Step No.%d, b = %.16f, |a-b| = %.16e\n", i, b, fabs(a-b));
        if(fabs(a-b) < EPSILON ) {
            break;
        }
        else {
            a = b;
        }
        i += 1;
    }
    return 0;
}

double func(double x)
{
    return pow(x, 3.) + (9.*pow(x, 2.)) + (18.*x) - (12.);
}

double dfunc(double x)
{
    return (3.*pow(x, 2)) + (18.*x) + 18.;
}
