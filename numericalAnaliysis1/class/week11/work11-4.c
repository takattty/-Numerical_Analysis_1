#include <stdio.h>
#include <math.h>

#define N 5
#define EPSILON 1.e-8
#define MAX_LOOP 50


int main(void) {
  double a[N][N+2] = {
    { 10.0, 3.0, 1.0, 2.0, 1.0, -22.0 },
    { 1.0, 19.0, 2.0, -1.0, 5.0, 27.0 },
    { -1.0, 1.0, 30.0, 1.0, 10.0, 89.0 },
    { -2.0, 0.0, 1.0, 20.0, 5.0, -73.0 },
    { -3.0, 5.0, 1.0, -2.0, 25.0, 22.0 }
  };

  double x[N], y[N], s, q;
  int i, j, k;

  for (i=0; i<N; i++) {
    x[i] = 0.0;
  }
  printf("Initial data\n");
  for(i=0; i<N; i++) {
    printf( "x%d = %9.7f ", i, x[i]);
  }
  printf("\n\n");

  printf("Iteration\n");
  for(k=0; k<MAX_LOOP; k++) {
    q = 0.0;
    printf("%2d ", k);

    for(i=0; i<N; i++){
      s = 0.0;
      for(j=0; j<N; j++){
	      if(i!=j){
	        s += a[i][j] * x[j];
	      }
      }
      y[i] = ( a[i][N] - s ) / a[i][i];
      q += fabs( y[i] - x[i] );
      x[i] = y[i];
      printf("x%d = %9.7f " , i, y[i] );
    }
    printf("\n");

    if ( q < EPSILON ) {
      printf("\n");
      printf("solution\n");
      for(i=0; i<N; i++){
	      printf("x%d = %9.7f\n", i, x[i]);
      }
      return 0;
    }
  }
  printf("no limit\n");
  return 1;
}
