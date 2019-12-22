#include <stdio.h>
#include <math.h>

#define EPSILON 1.e-15

double func(double);

int main(void)
{
  double a = 0. ;
  double b = 1. ;
  double x ;

  printf("Initial value a = %f\n", a);
  printf("Initial value b = %f\n", b);
  int i = 1;
  double c;
  while( fabs(a-b) > EPSILON ) {
    c = (a + b) / 2. ;
    if ( (func(a) * func(c)) < 0. ){
      b = c;
    }
    else {
      a = c;
    }
    printf("Step No.%2d, c=%.16f, |a-b|=%.16e\n", i, c, fabs(a-b));
    i += 1;
  }
  return 0;
}

double func(double x)
{
  return pow(x, 3.) + x - 1. ;
}
