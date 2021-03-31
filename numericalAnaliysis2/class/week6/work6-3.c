#include <stdio.h>
#include <math.h>

int i, k, j, k;
double simpson(int n);

int main(void) {
  FILE *fp;
  fp = fopen("work6-3.d", "w");
  for (i=1; i<=5; i++) {
    int n = pow(10, i);
    double integ = simpson(n);
    double error= fabs( (log(2) - integ) / log(2) );
    fprintf(fp, "%6d %.16e\n", n ,error);
  }
  fclose(fp);

  return 0;
}

double simpson(int n) {
  int m = n / 2.;
  double h = 1. / (double)n;
  double integ_odd = 0.;
  double integ_even = 0.;

  for (j=1; j<=m; j++) {
    double xx = ((2.*(double)j - 1.) * h);
    integ_odd += (1. / (1. + xx));
  }
  for (k=1; k<m; k++) {
    double yy = (2.*(double)k*h);
    integ_even += (1. / (1. + yy));
  }

  double integ = (h / 3.) * ((3. / 2.) + (4. * integ_odd) + (2. * (integ_even)));
  
  return integ;
}