#include <stdio.h>
#include <math.h>

int main(void) {
  int i;
  FILE *fp1;
  fp1 = fopen("work13-1-1.d", "w");
  double n1 = 10.;
  double dt1 = 10. / (double)n1;
  double vO1 = 50;
  double theta_deg1 = 45;
  double theta_rad1 = theta_deg1 * M_PI / 180. ;
  double vx1 = vO1 * cos(theta_rad1);
  double vz1 = vO1 * sin(theta_rad1);
  double x1 = 0.;
  double z1 = 0.;
  double g1 = 9.80665;

  for (i=0; i<=n1; i++) {
    fprintf(fp1, "%.16f %.16f\n", x1, z1);
    x1 += dt1 * vx1;
    z1 += dt1 * vz1;
    vz1 += -dt1 * g1;
  }

  fclose(fp1);

  FILE *fp2;
  fp2 = fopen("work13-1-2.d", "w");
  double n2 = 100.;
  double dt2 = 10. / (double)n2;
  double vO2 = 50;
  double theta_deg2 = 45;
  double theta_rad2 = theta_deg2 * M_PI / 180. ;
  double vx2 = vO2 * cos(theta_rad2);
  double vz2 = vO2 * sin(theta_rad2);
  double x2 = 0.;
  double z2 = 0.;
  double g2 = 9.80665;

  for (i=0; i<=n2; i++) {
    fprintf(fp2, "%.16f %.16f\n", x2, z2);
    x2 += dt2 * vx2;
    z2 += dt2 * vz2;
    vz2 += -dt2 * g2;
  }

  fclose(fp2);


  FILE *fp3;
  fp3 = fopen("work13-1-3.d", "w");
  double n3 = 1000.;
  double dt3 = 10. / (double)n3;
  double vO3 = 50;
  double theta_deg3 = 45;
  double theta_rad3= theta_deg3 * M_PI / 180. ;
  double vx3 = vO3 * cos(theta_rad3);
  double vz3 = vO3 * sin(theta_rad3);
  double x3 = 0.;
  double z3 = 0.;
  double g3 = 9.80665;

  for (i=0; i<=n3; i++) {
    fprintf(fp3, "%.16f %.16f\n", x3, z3);
    x3 += dt3 * vx3;
    z3 += dt3 * vz3;
    vz3 += -dt3 * g3;
  }

  fclose(fp3);
  return 0;
}