#include <stdlib.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

int nota (Aluno a) {
    float miniT = 0;
    float teste;
    for (int i = 0; i < 6; i++) {
        miniT += (float) a.miniT[i];
    }
    miniT /= 6;
    miniT *= 0.3;

    teste = a.teste;
    teste *= 0.7;

    float final = teste + miniT;
    if (final < 9.5) return 0;

    else 
        return final;
}

int procuraNum (int num, Aluno t[], int N) {
    for (int i = 0; i < N; i++) {
        if (num == t[i].numero) return i;
    }
    return -1;
}

void ordenaPorNum (Aluno t [], int N) {
    for (int i = 0; i < N; i++) {
        Aluno x = t[i];
        int j;
        for (j = i; j > 0 && x.numero < t[j-i].numero; j--) t[j] = t[j-1];
        t[j] = x;
    }
}

void imprimeTurma (int ind[], Aluno t[], int N) {
    ordenaPorNum(t, N);

    for (int i = 0; i < N; i++) {
        printf("Numero: %d\n", t[i].numero);
        printf("Nome: %s\n", t[i].nome);
        printf("Mini testes: {");
        for (int j = 0; j < 6; j++) {
            printf("%d, ", t[i].miniT[j]);
        }
        printf("}\n");
        printf("Teste: %d\n", t[i].teste);
    }
}