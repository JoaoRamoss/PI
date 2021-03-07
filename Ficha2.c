#include <stdio.h>

//1
float multInt1 (int n, float m) {
    float r = 0;
    for (int i = 0; i < n; i++)
        r += m;
    return r;
}

//2
float multInt2 (int n, float m) {
    int i = 0, r = 0;
    while (n > 0) {
        if (n % 2 != 0)
            r += m;
        n /= 2;
        m *=2;
    }
    return r;
}

//3
int mdc1 (int a, int b) {
    int mdc = 0, i;
    //Coloca em max o maior dos dois elementos (a ou b)
    for (i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0)
            mdc = i;
    }
    return mdc;
}

//4
int mdc2 (int a, int b) {
    if (a == b) return a;
    else if (a > b) return mdc2(a-b, b);
    else if (a < b) return mdc2(a, b-a);

    return 0;
}

//5
int mdc3 (int a, int b) {
    if (a == 0) return b;
    else if (b == 0) return a;
    else if (a > b) return mdc3(b, a%b);
    else if (b > a) return mdc3(b%a, a);

    return 0;
}

//6 a)
int fib1 (int n) {
    if (n <= 2) return 1;
    else return (fib1(n-1) + fib1(n-2));
}

//6 b)
int fib2(int n) {
    int ant1 = 0, ant2 = 1, soma = 0;
    if (n == 1 || n == 2)
        return 1;
    else {
        for (int i = 1; i < n; i++) {
            soma = ant1 + ant2;
            ant1 = ant2;
            ant2 = soma;
        }   
    }
    return ant2;
}

int main () {
    int teste = fib2(9);
    printf("fib: %d\n", teste);
}