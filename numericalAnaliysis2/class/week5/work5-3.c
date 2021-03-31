#include <stdio.h>
#include <math.h>

int main(void) {
  int i, j, k;
  FILE *fp;
  fp = fopen("work5-4.dat", "w");

  for (i=1; i<=5; i++) {
    int n = pow(10, i);
    int m = n / 2;
    double h = M_PI_2 / (double)n;

    double integ_odd = 0. ;
    for (j=1; j<=m; j++) {
      double xx = (2. *(double)j - 1.) * h;
      integ_odd += sin(xx);
    }

    double integ_even = 0. ;
    for (k=1; k<m; k++) {
      double yy = (2. * (double)k * h);
      integ_even += sin(yy);
    }

    double integ = (h/3.) * (1. + (4.*integ_odd) + (2.*integ_even));
    double error = fabs(1. - integ)/1.;
    fprintf(fp, "%5d %6d %.16f %.16e\n", m, n, integ, error);
  }
  fclose(fp);
  return 0;
}