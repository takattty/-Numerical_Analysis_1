#include <stdio.h>
#include <math.h>

int main(void) {
  int i, j;
  FILE *fp;
  fp = fopen("work13-1.d", "w");

  for (j=1; j<=2; j++) {
    int nn = pow(10., j);
    double dt = 10. / (double)nn;
    double vO = 50.;
    double theta_deg = 45.;

    double theta_rad = theta_deg * M_PI / 180. ;
    double vx = vO * cos(theta_rad);
    double vz = vO * sin(theta_rad);

    double x = 0.;
    double z = 0.;
    double g = 9.80665;

    for (i=0; i<=nn; i++) {
      double exactSolution = ( -((1./2.)*g*pow(x/vx, 2.)) + (vz/vx)*x );
      fprintf(fp, "%.16f %.16f %.16f\n", x, z, exactSolution);
      x += dt * vx;
      z += dt * vz;
      vz += -dt * g;
    }
  }
  fclose(fp);
  return 0;
}