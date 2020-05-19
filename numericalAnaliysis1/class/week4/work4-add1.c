#include <stdio.h>
#include <math.h>

#define EPSILON 1.e-4

double nibun(double, double);
double func(double);

int main(void)
{
  double a = 0. ;
  double b = 1. ;
  double x ;

  printf("Initial value a = %f\n", a);
  printf("Initial value b = %f\n", b);
  x = nibun(a, b);
  printf("Approx. sol.  x=%f\n", x);
  return 0;
}

double nibun(double a, double b)
{
  double c;
  while( fabs(a-b) > EPSILON ) {
    c = (a + b) / 2. ;
    if ( (func(a) * func(c)) < 0. ){
      b = c;
    }
    else {
      a = c;
    }
  }
  return c;
}

double func(double x)
{
  return cos(x) - pow(x, 2.) ;
}
