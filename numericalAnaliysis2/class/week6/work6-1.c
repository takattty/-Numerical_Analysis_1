#include <stdio.h>
#include <math.h>

double kubun(int n);

int main(void) {
  int i;
  FILE *fp;
  fp = fopen("work6-1.d", "w");

  for (i=1; i<=3; i++) {
    int n= pow(10, i);
    double integ_kubun = kubun(n);
    double error_kubun = fabs(1. - integ_kubun);
    fprintf(fp, "%5d %.16e\n", n ,error_kubun);
  }
  fclose(fp);

  return 0;
}

double kubun(int n) {
  int k;
  double h = 0.5 * M_PI / (double)n;
  double integ = 0.;

  for (k=0; k<n; k++) {
    double xx = h * (double)k;
    integ += h * cos(xx);
  }

  return integ;
}