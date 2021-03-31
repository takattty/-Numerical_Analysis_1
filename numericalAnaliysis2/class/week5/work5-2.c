#include <stdio.h>
#include <math.h>

int main(void) {
  int i, j, k;
  printf("#   M   N=2M I                  Relative error\n");

  for (i=1; i<=5; i++) {
    int n = pow(10, i);
    int m = n / 2;
    double h = 1. / (double)n;
    double integ_odd = 0.;

    for (j=1; j<=m; j++) {
      double xx = (2.*(double)j - 1.) * h;
      integ_odd += exp(xx) + 1. ; 
    }
    double integ_even = 0.;

    for (k=1; k<m; k++) {
      double yy = 2.*(double)k * h;
      integ_even += exp(yy) + 1.;
    }

    double integ = (h/3.) * (M_E + 3. + 4.*integ_odd + 2.*integ_even);
    double error = fabs(M_E - integ)/M_E;
    printf("%5d %6d %.16f %.16e\n", m, n, integ, error);
  }
  return 0;
}