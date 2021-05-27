char *strcpy (char *dest, char source[]) {
    int i;
    for (int i = 0; dest[i]; dest[i] = source[i++]);
    dest[i] = 0;
    return dest; 
}

void strnoV (char s[]) {
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A' || s[i] == 'a' || s[i] == 'E' || s[i] == 'e' || s[i] == 'I' || s[i] == 'i' 
        || s[i] == 'O' || s[i] == 'o' || s[i] == 'U' || s[i] == 'u') {
            for (int j = i; s[j]; j++) 
                j[i] = j[i+1];
            i--;
        }
    }
}

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;

int dumpAbin (ABin a, int v[], int N) {
    int e, d;
    if (a && N) {
        e = dumpAbin(a->esq, v, N);
        if (e < N) {
            v[e] = a->valor;
            return 1 + e + dumpAbin(a->dir, v+e+1, N-e-1);
        }
        else return N;
    }
    return 0;
}

int lookupAB (ABin a, int x) {
    if (!a) return 0;
    while (a) {
        if (valor == x) return 1;
        else if (a->valor < x) a = a->esq;
        else a = a->dir;
    }
    return 0;
}

////////////////////

typedef struct listaP{
char *pal;
int cont;
struct listaP *prox;
} Nodo, *Hist;

int inc(Hist *h, char *pal) {
    int res = 0;
    Hist l = *h;

    while (l) {
        if (!strcmp(l->pal, pal)) {
            l->cont++;
            return l->cont;
        }
        l = l->prox;
    }
    if (!l) {
        Hist nova = malloc(sizeof(struct listaP));
        nova->cont = 1;
        nova->pal = pal;
        nova->prox = NULL;
        l = nova;
    }
    return 1;
}

char *remMaisFreq(Hist *h, int *count) {
    char *palavra;
    Hist l = *h, ant, prox, anterior, res;
    int max = INT_MIN;
    while (l) {
        if (l->cont > max) {
            max = l->cont;
            ant = anterior;
            res = l;
            prox = l->prox;
        }
        anterior = l;
        l = l->prox;
    }
    *count = max;
    if (!anterior) *h = (*h)->prox;
    else ant->prox = prox;

    palavra = res->pal;
    free(res);
    res = NULL;
    return palavra;
}

