#include <stdio.h>
#include <math.h>

int i, k;
double daikei(int n);

int main(void) {
  FILE *fp;
  fp = fopen("work6-2.d", "w");
  for (i=1; i<=5; i++) {
    int n = pow(10, i);
    double integ = daikei(n);
    double error= fabs( (log(2) - integ) / log(2) );
    fprintf(fp, "%6d %.16e\n", n ,error);
  }
  fclose(fp);

  return 0;
}

double daikei(int n) {
  double dx = 1. / (double)n;
  double integ = 0.;

  for (k=1; k<n; k++) {
    double xk = (double)k * dx;
    integ += (1. / (1. + xk));
  }
  integ = dx * ( (3./4.) + integ );

  return integ;
}