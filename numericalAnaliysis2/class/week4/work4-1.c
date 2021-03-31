#include <stdio.h>
#include <math.h>

int main(void) {
  int k, n;
  printf("Input a number (N) : ");
  scanf("%d", &n);

  double dx = 1. / (double)n;
  double integ = 0. ;

  for (k=1; k<n; k++) {
    double xx = (double)k * dx;
    integ += xx * xx;
  }
  
  integ = dx * ( 0.5 + integ );
  printf("N = %d  I = %.16f \n", n, integ);

  double error = fabs(1. - integ / (1./3.));
  printf("The relative error : %.16e \n", error);

  return 0;
}