#include <stdio.h>
#include <math.h>

double func1(double vr) {
  return vr;
}

double func2(double radius, double omega) {
  return (radius * pow(omega, 2.)) - (1. / pow(radius, 2.));
}

double func3(double omega) {
  return omega;
}

double func4(double radius, double vr, double omega) {
  return -((2. * vr * omega) / (radius));
}

int main(void)
{
  int i;

  double dt = 0.01;
  double radius = 1.;
  double theta = 0.;
  double vr = 0.;
  double omega = 1.2;

  double kr1, kr2, kr3, kr4;
  double kv1, kv2, kv3, kv4;
  double kt1, kt2, kt3, kt4;
  double ko1, ko2, ko3, ko4;

  FILE *fp;
  fp = fopen("work14-1.d", "w");

  for (i = 0; i <= 2000; i++)
  {
    fprintf(fp, "%.16f  %.16f  %.16f  %.16f\n", radius, theta, vr, omega);

    kr1 = func1(vr);
    kv1 = func2(radius, omega);
    kt1 = func3(omega);
    ko1 = func4(radius, vr, omega);

    kr2 = func1(vr + 0.5 * dt * kr1);
    kv2 = func2(radius + 0.5 * dt * kr1, omega + 0.5 * dt * ko1);
    kt2 = func3(omega + 0.5 * dt * ko1);
    ko2 = func4(radius + 0.5 * dt * kr1, vr + 0.5 * dt * kv1, omega + 0.5 * dt * ko1);

    kr3 = func1(vr + 0.5 * dt * kr2);
    kv3 = func2(radius + 0.5 * dt * kr2, omega + 0.5 * dt * ko2);
    kt3 = func3(omega + 0.5 * dt * ko2);
    ko3 = func4(radius + 0.5 * dt * kr2, vr + 0.5 * dt * kv2, omega + 0.5 * dt * ko2);

    kr4 = func1(vr + dt * kr3);
    kv4 = func2(radius + dt * kr3, omega + dt * ko3);
    kt4 = func3(omega + dt * ko3);
    ko4 = func4(radius + dt * kr3, vr + dt * kv3, omega + dt * ko3);

    radius += ((dt * (kr1 + 2. * kr2 + 2. * kr3 + kr4)) / 6.);
    vr += ((dt * (kv1 + 2. * kv2 + 2. * kv3 + kv4)) / 6.);
    theta += ((dt * (kt1 + 2. * kt2 + 2. * kt3 + kt4)) / 6.);
    omega += ((dt * (ko1 + 2. * ko2 + 2. * ko3 + ko4)) / 6.);
  }

  fclose(fp);
  return 0;
}