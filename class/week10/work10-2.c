#include <stdio.h>
#include <math.h>

#define N 4

int main(void) {
  double a[N][N] = {
      { 1.0, -4.0, 3.0, -1.0 },
      { 1.0, -5.0, 2.0, 1.0 },
      { 2.0, -5.0, 4.0, -3.0 },
      { -1.0, 4.0, -2.0, -2.0 }
      };

  double b[N] = { -3.0, 4.0, -7.0, -5.0 };

      int i, j, k, l;
      double m;

      printf("Initial matrix\n");
      for (i=0; i<N; i++) {
	for (j=0; j<N; j++) {
	  printf("%3.2f ", a[i][j]);
	}
	printf("\n");
      }
      printf("\n");

      for (l=0; l<N-1; l++){
	for(j=l+1; j<N; j++){
	  m = a[j][l] / a[l][l];
	  for(k=l+1; k<N; k++) {
	    a[j][k] -= m*a[l][k];
	  }

	  for(k=l; k<l+1; k++){
	    a[j][k] = a[j][k] / a[k][k];
	  }
	}
	
	printf("Intermediate matrix\n");

	for(i=0; i<N; i++) {
	  for(j=0; j<N; j++) {
	    printf("%3.2f ", a[i][j]);
	  }
	  printf("\n");
	}
	printf("\n");
      }

      printf("Final matrix\n");
      for(i=0; i<N; i++){
	for(j=0; j<N; j++){
	  printf("%3.2f ", a[i][j]);
	}
	printf("\n");
      }
      printf("\n");

      double y[N];
      y[0] = b[0];

      for(i=1; i<N; i++){
	y[i] = b[i];
	for(k=0; k<i; k++){
	  y[i] -= a[i][k] * y[k];
	}
      }

      for(i=0; i<N; i++){
	printf("y%d = %3.2f\n", i, y[i]);
      }
      printf("\n");

      double x[N];

      x[N-1] = y[N-1] / a[N-1][N-1];

      for(j=N-2; j>=0; j--){
	x[j] = y[j];
	for(k=N-1; k>j; k--){
	  x[j] -= a[j][k] * x[k];
	}
	x[j] /= a[j][j];
      }

      for(i=0; i<N; i++) {
	printf("x%d = %3.2f\n", i, x[i]);
      }
      return 0;
}
