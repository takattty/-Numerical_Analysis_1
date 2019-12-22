#include <stdio.h>
#include <math.h>

#define EPSILON 1.e-15

double bisection(double, double);
double func(double);


int main(void) {
    double a = -1.;
    double b = 2.;
    double x;
    bisection(a, b);
}

double bisection(double a, double b) {
    double c;
    int i = 1.;

    FILE *fp ;
    fp = fopen("report1-a.d", "w");

    while( fabs(a-b) > EPSILON ) {
        printf("Step No. %d, ", i);
        c = (a + b) / 2. ;
        if( (func(a) * func(c)) < 0. ) {
            b = c;
        } else {
            a = c;
        }
        printf("Approximate Solution = %.16f, ", c);
        printf("|a-b| = %.16e\n", fabs(a-b));
        fprintf(fp, "%d,  %.16f, %.16e\n", i, c, fabs(a-b));
        i += 1;
    }
    fclose(fp);
    return c;
}

double func(double x) {
    return exp(-x/2.)-(5.*pow(x, 3.));
}