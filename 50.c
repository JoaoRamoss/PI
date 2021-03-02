#include <stdio.h>

//1
void le_seq () {
    int max = 0;
    int c = 1;
    while (c != 0) {
        printf("Insere um numero: ");
        scanf("%d", &c);
        if (max < c) max = c;
    }
    printf("O maior número é: %d\n", max);
}

//2
void avg() {
    int i = 0;
    float c = 1, soma = 0;
    while (c != 0) {
        printf("Insere um numero: ");
        scanf("%f", &c);
        soma += c;
        i++;
    } 
    float media = soma/(i-1);
    printf("Media: %.2f\n", media);
}

//3
void segundo_maior () {
    int max = 0, second = 0;
    int c = 1;
    while (c != 0) {
        printf("Insere um numero: ");
        scanf("%d", &c);
        if (c > max) {
            second = max;
            max = c;
        }
        else if (c > second && c < max) second = c;
    }
    printf("O segundo maior e: %d\n", second);
}

//4
int bitsUm(unsigned int n) {
    int count1 = 0;
    while (N > 0) {
        if (N % 2 != 0)
            count1++;
        N /= 2;
    }
    return count1;
}

//5
int trailingZ (unsigned int n) {
    int count = 0, i;
    //int tem 32 bits
    for (i = 0; i < 32; i++, n /= 2) {
        if (n % 2 != 0)
            break;
        else 
            count++;
    }
    return count;
}

//6
int qDig (unsigned int n) {
    int count = 0;
    if (n == 0) return 1;
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}

//7
char *mystrcat (char s1[], char s2[]) {
    int i, k, j;
    for (i = 0; s1[i] != 0; i++);
    for (k = 0; s2[k] != 0; k++, i++)
        s1[i] = s2[k];

    s1[i] = '\0';
    return s1;
}

//8
char *mystrcpy (char *dest, char source []) {
    int i;
    for (i = 0; source[i] != 0; i++) {
        dest[i] = source[i];
    }
    dest[i] = 0;
    return dest;
}

//9
int mystrcmp (char s1 [], char s2 []) {
    int i = 0;
    while (i != -1){
        if (s1[i] == 0 && s2[i] == 0)
            return 0;
        else if (s1[i] == 0 && s2[i] != 0)
            return -1;
        else if (s1 [i] != 0 && s2 [i] == 0)
            return 1;
        else if (s1 [i] > s2 [i])
            return 1;
        else if (s1 [i] < s2 [i])
            return -1;
        i++;
    }
}

//10 (incompleto ainda)
char  *mystrstr (char s1 [], char s2 []) {
    int i,j, pos = 0, k;
    for (i = 0; s1[i] != 0; i++) {
        if (s2[0] == s1[i]) {
            for (j = 0, k = i; s2[j] != 0; j++, k++) 
                if (s2[j] != s1[k]) return NULL;
                pos = &s1[i];
                return pos;
        }
    }
    return NULL;
}

int main () {
    return 0;
}