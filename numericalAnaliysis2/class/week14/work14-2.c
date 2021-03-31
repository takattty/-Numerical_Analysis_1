#include <stdio.h>
#include <math.h>

int i, j, k, l;
double k1, k2, x, t;
double rungex();
double rungev();
double t = 0.;
double x0 = 0.;
double v0 = 1.;
double dt = 1./1000.;

int main(void) {
  FILE *fp;
  fp = fopen("work14-2.d", "w");

  for (l=0; l<=10; l++) {
    double x = rungex();
    double v = rungev();
    t = l;

    fprintf(fp, "%6.3f %.16f %.16f\n", t, x, v);
  }

  fclose(fp);
  return 0;
}

double rungex() {
  for (j=0; j<1000; j++) {
    printf("rungex t is %.16f\n\n", t);
    k2 = (v0 + 0.5*dt);
    x0 += dt*k2;
    t += dt;
  }
  return x0;
}

double rungev() {
  double omega = sqrt(10.);
  double lamda = 1.;

  for (k=0; k<1000; k++) {
    printf("rungev t is %.16f\n\n", t);
    k1 = -((pow(omega, 2.)*x0) + 2.*lamda*v0);
    k2 = -((pow(omega, 2.)*x0) + 2.*lamda*v0 + 0.5*dt*k1);
    v0 += (dt*k2);
    t += dt;
  }

  return v0;
}