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

    FILE *fp ;
    fp = fopen("report1-b.d", "w");

    while(1) {
        b = a - func(a) / dfunc(a);
        printf("Step No.%d, b=%.16f, |a-b|=%.16e\n", i, b, fabs(a-b));
        fprintf(fp, "%d, %.16f, %.16e\n", i, b, fabs(a-b));
        if(fabs(a-b) < EPSILON ) {
            break;
        }
        else {
            a = b;
        }
        i += 1;
    }
    
    fclose(fp);
    return 0;
}

double func(double x)
{
    return exp(-x/2.)-(5.*pow(x, 3.));
}

double dfunc(double x)
{
    return -(exp(-x/2.)/2)-(15.*pow(x, 2));
}
