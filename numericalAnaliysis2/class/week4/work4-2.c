#include <stdio.h>
#include <math.h>

int main(void) {
  int k, n;
  printf("Input a number (N) : ");
  scanf("%d", &n);

  double dx = 1. / (double)n;
  double integ = 0. ;
  
  for ( k=1; k<n; k++ ) {
    double xk = (double)k * dx;
    integ += (1. + pow(xk, 4.));
  }

  integ = dx * ( 1.5 + integ );
  printf("N = %d  I = %.16f \n", n, integ);

  double error = fabs(1. - integ / (1./3.));
  printf("The relative error : %.16f \n", error);

  return 0;
}