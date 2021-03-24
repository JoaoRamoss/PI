
#include <stdio.h>



int oblongos (int n) {
    int f = 0;
    for (int i = 0; i < n; i++) {
        if (n == (i * (i+1))) f = 1;
    }
    return f;
}

int sumhtpo (int n){
  int r = 0, x = 0, y = 0, count = 0;
  while (n != 1) {
    r += n;
    if(n%2 == 0) {
    n = n/2;
        y++;
    }
    else {
         n = 1+(3*n);
         x++;
    }
    if (oblongos(n) == 1) count++;
  }
  printf("Oblongos: %d\n", count);
  printf("Impares: %d\n", x);
  printf("Pares: %d\n", y);
  return r;
}

int main () {
    sumhtpo(31);
}