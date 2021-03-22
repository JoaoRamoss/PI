#include <stdio.h>
#include <limits.h>
#include <math.h>

//2
void swapM (int *x, int *y) {
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

//3
void swap (int v[], int i, int j) {
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

//4
int soma (int v[], int N) {
    int soma = 0;
    for (int i = 0; i < N; soma += v[i++]);
    return soma;
}

//5a
void inverteArray (int v[], int N) {
    for (int i = 0, k = N-1; i < N/2; swap(v, i++, k--));
}

//5b
void inverteArray2 (int v[], int N) {
    for (int i = 0, k = N-1; i < N/2; swapM(&v[i++], &v[k--])); 
}

//5
int maximum (int v[], int N, int *m) {
    int max = INT_MIN;

    if (N < 0) return 1;

    for (int i = 0; i < N; i++) {
        if (v[i] > max) 
            max = v[i];
    }
    *m = max;
    return 0;
}

//7
void quadrados (int q[], int N) {
    for (int i = 0, k = 0; i < N; q[i++] = pow(k++, 2)); 
}

int main () {
    int v[5];
    quadrados(v, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}