#include <stdio.h>
#include <math.h>

int i, n;
double k1, k2, k3, k4;

int main(void) {

  FILE *fp;
  fp = fopen("work12-3.d", "w");
  double integ = (exp(1.)+2.)/(exp(1.)+1.);

  for (n=0; n<=5; n++) {
    int nn = pow(10., n);
    double dt = 1. / (double)nn;
    double t = 0.;
    double u = 0.5;
    for (i=0; i<nn; i++) {
      k1 = ( (pow(t, 2.) + t + 1.) - (2.*t + 1.)*u + pow(u, 2.));
      k2 = ( (pow(t+0.5*dt, 2.) + (t+0.5*dt) + 1.) - (2.*(t+0.5*dt) + 1.)*(u+0.5*dt*k1) + pow(u+0.5*dt*k1, 2.) );
      k3 = ( (pow(t+0.5*dt, 2.) + (t+0.5*dt) + 1.) - (2.*(t+0.5*dt) + 1.)*(u+0.5*dt*k2) + pow(u+0.5*dt*k2, 2.) );
      k4 = ( (pow(t+dt, 2.) + (t+dt) + 1.) - (2.*(t+dt))*(u+dt*k3) + pow(u+dt*k3, 2.) );
      u += dt * (k1 + 2.*k2 + 2.*k3 + k4) / 6.;
      t += dt;
    }
    double error = fabs((integ - u)/ integ );
    fprintf(fp, "%6d %.16e\n", nn, error);
  }

  fclose(fp);
  return 0;
}