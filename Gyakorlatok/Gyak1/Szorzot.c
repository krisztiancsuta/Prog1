#include <stdio.h>
 
int main(void) {
  for (int y = 1; y <= 10; y = y+1) {
    for (int x = 1; x <= 10; x = x+1)
      printf("%4d", x * y);// %3d ben a 3 as az 3 karakternyi helyet foglal le 
    printf("\n");
  }
  
  return 0;
}
