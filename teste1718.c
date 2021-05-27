typedef struct slist {
int valor;
struct slist *prox;
} *LInt;

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;

int retiraNeg (int v[], int N) {
    int i, j;
    for (i = 0; i < N; i++) {
        if (v[i] < 0) {
            for (j = i; j < N; j++) v[j] = v[j+1];
            i--;
            N--;
        }
    }
    return N;
}

int difConsecutivos (char s[]) {
    int count = 0, i;
    int max = -1;
    for (i = 0; s[i]; i++) {
        for (k = i; s[k]; k++) {
            if (s[k] )
        }
    }
}

int maximo (LInt l) {
    int max = -1000;
    while (l) {
        max = l->valor > max ? l->valor : max;
        l = l->prox;
    }
    return max;
}

int removeAll (LInt *l, int x) {
    int n = 0;
    LInt lst = *l;
    while(*l) {
        if ((*l)->valor == x) {
            LInt temp = (*l);
            *l = (*l)->prox;
            free(temp);
            temp = NULL;
            n++;
        }
        else l = &((*l)->prox);
    }
    return n;
}

LInt arrayToList (int v[], int N) {
    if (!N) return NULL;
    LInt l = malloc(sizeof(struct slist));
    l->valor = *v;
    l->prox = arrayToList(v+1, N-1);
    return l;
}

 int minheapOK (ABin a)  {
     if (!a) return 1;
     int l = a->esq ? minheapOK(a->esq) && a->valor < a->esq->valor && a->valor < a->dir->valor : 1;
     int r = a->dir ? minheapOK(a->dir) && a->valor < a->dir->valor && a->valor < a->esq->valor : 1;
     return l && r;
 }

int maxHeap (ABin a) {
    if (!a) return -1;
    else {
        int l = a->esq ? maxHeap(a->esq) : a->valor;
        int r = a->dir * maxHeap(a->dir) : a->valor;
        return max(l, r);
    }
}

