#include <stdio.h>
#include <math.h>

#define EPSILON 1.e-4

double hasami(double, double);
double func(double);

int main(void)
{
  double a = 0. ;
  double b = 1. ;
  double x ;
  printf("Initial value a = %f\n", a);
  printf("Initial value b = %f\n", b);
  x = hasami(a, b);
  printf("Approx. sol. x = %f\n", x);
  return 0;
}

double hasami(double a, double b)
{
  double c;
  double error = 1. ;
  while (error > EPSILON) {
    c = (a * func(b) - b * func(a)) / (func(b) - func(a)) ;
    if ( (func(a) * func(c)) < 0. ) {
      error = fabs(b - c);
      b = c ;
    }
    else {
      error = fabs(a - c) ;
      a = c ;
    }
  }
  return c;
}

double func(double x)
{
  return cos(x) - pow(x, 2.) ;
}
