#include <stdio.h>
#include <math.h>

int main(void) {
  int i, n;
  double k1, k2, k3, k4;

  FILE *fp;
  fp = fopen("work12-1.d", "w");

  for (n=0; n<=4; n++) {
    int nn = pow(10., n);
    double u = 1.;
    double dt = 0.5 / (double)nn;

    for (i=0; i<nn; i++) {
      k1 = pow(u, 2.);
      k2 = pow(u + 0.5*dt*k1, 2.);
      k3 = pow(u + 0.5+dt*k2, 2.);
      k4 = pow(u + dt*k3, 2.);
      u += dt * (k1 + 2.*k2 + 2.*k3 + k4) / 6.;
    }

    double error = fabs(1. - u/2.);
    fprintf(fp, "%5d %.16e\n", nn, error);
  }

  fclose(fp);
  return 0;
}