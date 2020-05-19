#include <stdio.h>

int main(void) {
  int i;
  int a = 0;
  FILE *fp;

  fp = fopen("test1.d", "w");
  for (i=0; i<10; i++) {
    a += i;
    fprintf(fp, "%d\n", a);
  }
  fclose(fp);

  return 0;
}