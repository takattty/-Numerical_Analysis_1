#include <stdio.h>
#include <math.h>

#define EPSILON 1.e-15

double bisection(double, double);
double func(double);


int main(void) {
    double a = -1.;
    double b = 2.;
    double x;

    x = bisection(a, b);
    printf("Final number = %f\n", x);
}

double bisection(double a, double b) {
    double c;
    int i = 1.;
    while( fabs(a-b) > EPSILON ) {
        printf("Step No. %d\n", i);
        i += 1;
        c = (a + b) / 2. ;
        if( (func(a) * func(c)) < 0. ) {
            b = c;
        } else {
            a = c;
        }
        printf("Approximate Solution = %.16f\n", c);
        printf("|a-b| = %.16e\n", fabs(a-b));
    }
    return c;
}

double func(double x) {
    return exp(-x/2.)-(5.*pow(x, 3.));
}