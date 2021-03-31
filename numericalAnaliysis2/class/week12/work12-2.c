#include <stdio.h>
#include <math.h>

int main(void) {
  int i, n;
  double k1, k2, k3, k4;

  FILE *fp;
  fp = fopen("work12-2.d", "w");

  for (n=0; n<=3; n++) {
    int nn = pow(10., n);
    double t = 0.;
    double u = 1.;
    double dt = 1. / (double)nn;

    for (i=0; i<nn; i++) {
      // k1 = u / (1. + t) / (1. + t);
      k1 = u / ((1. + t)*(1. + t));
      // k2 = (u + 0.5*dt*k1) / (1. + t + 0.5*dt) / (1. + t + 0.5*dt);
      k2 = (u + 0.5*dt*k1) / ((1. + t + 0.5*dt)*(1. + t + 0.5*dt));
      // k3 = (u + 0.5*dt*k2) / (1. + t + 0.5*dt) / (1. + t + 0.5*dt);
      k3 = (u + 0.5*dt*k2) / ((1. + t + 0.5*dt)*(1. + t + 0.5*dt));
      // k4 = (u + dt*k3) / (1. + t + dt) / (1. + t + dt);
      k4 = (u + dt*k3) / ((1. + t + dt)*(1. + t + dt));
      u += dt * (k1 + 2.*k2 + 2.*k3 + k4) / 6.;
      t += dt;
    }

    double error = fabs(1. - u/sqrt(M_E));
    fprintf(fp, "%6d %.16e\n", nn, error);
  }

  fclose(fp);
  return 0;
}