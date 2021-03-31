#include <stdio.h>
#include <math.h>

int main(void) {
  int k, i;
  FILE *fp;

  fp = fopen("test.d", "w");
  
  for (i=1; i<=4; i++) {
    int n = pow(10, i);
    double dx = 1. / (double)n;
    double integ = 0.;

    for (k=1; k<n; k++) {
      double xx = dx * (double)k;
      integ += pow(xx, 2.);
    }
    integ = dx * ( 0.5 + integ );

    double error = fabs(1. - integ / (1./3.));
    fprintf(fp, "%5d %.16f\n", n, error);
  }
  fclose(fp);
  return 0;
}
