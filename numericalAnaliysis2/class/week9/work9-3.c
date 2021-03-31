#include <stdio.h>
#include <math.h>

int i, j, n;
double rungekutta(int n), k1, k2;

int main(void) {
  FILE *fp;
  fp = fopen("work9-3.d", "w");
  double integ = exp(1./2.);

  for (i=0; i<=4; i++) {
    int n = pow(10,i);
    double rungekuttaInteg = rungekutta(n);
    double error = fabs ( (integ - rungekuttaInteg) / integ );
    fprintf(fp, "%5d %.16e\n", n, error);
  }

  fclose(fp);
  return 0;
}

double rungekutta (n) {
  double dt = 1. / (double)n;
  double u = 1.;
  double t = 0.;
  
  for (j=0; j<n; j++) {
    k1 = u / pow((1. + t), 2.);
    k2 = (u + 0.5*dt*k1) / pow((1. + (t+0.5*dt)), 2.);
    u += dt * k2;
    t += dt;
  }

  return u;
}