#include <stdio.h>
#include <math.h>

#define N 4

int main(void) {
  double a[N][N] = {
    { 9.0, 2.0, 1.0, 1.0},
    { 2.0, 8.0, -2.0, 1.0},
    { -1.0, -2.0, 7.0, -2.0},
    { 1.0, -1.0, -2.0, 6.0}
  };

  double b[N] = { 20.0, 16.0, 8.0, 17.0 };
  int i, j, k, l;
  double m;

  FILE *fp;
  fp = fopen("a-2.d", "w");

  for (i=0; i<N; i++) {
	  for (j=0; j<N; j++) {
	    //printf(" %.12f  ", a[i][j]);
	  }
  }

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

	  for(i=0; i<N; i++) {
	    for(j=0; j<N; j++) {
	      //printf(" %.12f  ", a[i][j]);
	    }
	  }
  }

  for(i=0; i<N; i++){
	  for(j=0; j<N; j++){
	    //printf(" %.12f  ", a[i][j]);
    }
  }

  double y[N];
  y[0] = b[0];

  for(i=1; i<N; i++){
	  y[i] = b[i];
	  for(k=0; k<i; k++){
	    y[i] -= a[i][k] * y[k];
	  }
  }

  for(i=0; i<N; i++){
	  //printf("y%d = %.12f\n", i, y[i]);
  }

  double x[N];
  x[N-1] = y[N-1] / a[N-1][N-1];

  for(j=N-2; j>=0; j--){
	  x[j] = y[j];
	  for(k=N-1; k>j; k--){
	    x[j] -= a[j][k] * x[k];
	  }
	  x[j] /= a[j][j];
  }

  printf("Soloution\n");
  fprintf(fp, "Soloution\n");
  for(i=0; i<N; i++) {
	  printf("x%d = %.12f\n", i, x[i]);
    fprintf(fp, "x%d = %.12f\n", i, x[i]);
  }

  fclose(fp);
  return 0;
}
