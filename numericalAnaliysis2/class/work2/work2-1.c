#include <stdio.h>
#include <math.h>

int i, j, n;
double oira (int n);
double rungekutta(int n), k1, k2;

int main(void) {
  FILE *fp;
  fp = fopen("work2-1.d", "w");
  double integ = exp(2.)*M_LN2;

  for (i=0; i<=5; i++) {
    int n = pow(10,i);
    double oiraInteg = oira(n);
    double rungekuttaInteg = rungekutta(n);
    double oiraError = fabs( (integ - oiraInteg) / integ );
    double rungekuttaError = fabs ( (integ - rungekuttaInteg) / integ );
    fprintf(fp, "%6d %.16e %.16e\n", n, oiraError, rungekuttaError);
  }

  fclose(fp);
  return 0;
}

double oira (n) {
  double dt = 1. / (double)n;
  double t = 1.;
  double u = 0.;

  for (j=0; j<n; j++) {
    u += dt * (u + (exp(t) / t));
    t += dt;
  }

  return u;
}

double rungekutta (n) {
  double dt = 1. / (double)n;
  double t = 1.;
  double u = 0.;
  
  for (j=0; j<n; j++) {
    k1 = u + ( exp(t) / t );
    k2 = (u + (0.5*dt*k1)) + ( exp(t+0.5*dt)/(t+0.5*dt) );
    u += dt * k2;
    t += dt;
  }

  return u;
}