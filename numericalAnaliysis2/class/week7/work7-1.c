#include <stdio.h>
#include <math.h>

int i, j, k;
double kubun(int n);
double daikei(int n);
double simpson(int n);

int main(void) {
  FILE *fp;
  fp =fopen("work7-1.dat", "w");
  for (i=1; i<=5; i++) {
    int n = pow(10, i);
    double kubunInteg = kubun(n);
    double kubunError = fabs(((exp(sqrt(2.)) - exp(1.)) - kubunInteg) / (exp(sqrt(2.)) - exp(1.)));
    double daikeiInteg = daikei(n);
    double daikeiError = fabs(((exp(sqrt(2.)) - exp(1.)) - daikeiInteg) / (exp(sqrt(2.)) - exp(1.)));
    double simpsonInteg = simpson(n);
    double simpsonError = fabs(((exp(sqrt(2.)) - exp(1.)) - simpsonInteg) / (exp(sqrt(2.)) - exp(1.)));
    fprintf(fp, "%6d %.16e %.16e %.16e\n", n, kubunError, daikeiError, simpsonError);
  }
  fclose(fp);

  return 0;
}

double kubun(int n) {
  double dx = 1. / n;
  double kubunInteg = 0.;

  for (k=0; k<n; k++) {
    double xx = 1. + (double)k * dx;
    kubunInteg += dx * (exp(sqrt(xx))/(2.*sqrt(xx)));
  }

  return kubunInteg;
}

double daikei(int n) {
  double dx = 1. / (double)n;
  double daikeiInteg = 0.;

  for (k=1; k<n; k++) {
    double xx = 1. + ((double)k * dx);
    daikeiInteg += (exp(sqrt(xx))/(2.*sqrt(xx)));
  }

  daikeiInteg = dx * (0.5 * ((exp(1.)/2.) + (exp(sqrt(2.))/(2.*sqrt(2.)))) + daikeiInteg);
  return daikeiInteg;
}

double simpson(int n) {
  int m = n / 2.;
  double h = 1. / (double)n;
  double integ_odd = 0.;
  double integ_even = 0.;

  for (j=1; j<=m; j++) {
    double xx = 1. + (2. * (double)j - 1.) * h;
    integ_odd += ( exp(sqrt(xx))/(2.*sqrt(xx)) );
  }
  for (k=1; k<m; k++) {
    double yy = 1. + (2. * (double)k * h);
    integ_even += (exp(sqrt(yy))/(2.*sqrt(yy)));
  }

  double simpsonInteg = (h / 3.) * (((exp(1.))/(2.)) + (4. * integ_odd) + (2. * integ_even) + ((exp(sqrt(2.)))/(2.*sqrt(2.))));
  return simpsonInteg;
}