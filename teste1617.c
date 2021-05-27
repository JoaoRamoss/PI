typedef struct slist {
int valor;
struct slist *prox;
} *LInt;

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;


"Ola  mundo"
"Ola mundo"


int limpaEspacos (char t[]) {
    int i;
    int len;
    for (len = 0; t[len]; len++);
    for (i = 1; t[i]; i++) {
        if (t[i] == ' ' && t[i-1] == ' ') {
            for (k = i; t[k]; k++) 
                t[k] = t[k+1];
            i--;
            len--;
        }
    }
    return len;
}

 void transposta (int N, float m [N][N]) {
     for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
             float aux = m[i][j];
             m[i][j] = m[j][i];
             m[j][i] = aux;
         }
     }
 }

 LInt cloneL (LInt l) {
     if (!l) return NULL;
     LInt res = malloc(sizeof(struct lligada));
     res->valor = l->valor;
     res->prox = cloneL(l->prox);
     return res;
 }

int nivelV (ABin a, int n, int v[])  {
    if (!a || n < 1) return 0;
    if (n == 1) {
        *v = a->valor;
        return 1;
    }
    else {
        int e = nivelV(a->esq, n-1, v);
        int d = nivelV(a->dir, n-1, v+e);
        return d + e;
    }
}

void removeMaiorA (ABin *a) {
    ABin parent = NULL;
    if (*a) {
        while((*a)->dir) {
            parent = *a;
            a = &((*a)->dir);
        }

        free(*a);
        a = NULL;
        *parent->dir = NULL;
    }
}

typedef struct chunk {
int vs [MAXc];
struct chunk *prox;
} *CList;

typedef struct stackC {
CList valores;
int sp;
} StackC;

push (StackC *s, int x) {
    if (!*s) {

    }
    if ((*s)->sp < MAXc-1) {
        (*s)->valores->vs[(*s)->sp] = x;
        (*s)->sp++;
    }
    else {

    }
}

int pop (StackC *s, int *x) {
    if (!s || !s->valores) return 1;
    *x = (*s)->valores->vs[--(*s)->sp];
    if ((*s)->sp == 0) {
        (*s)->sp = MAXc;
        CList temp = (*s)->valores;
        (*s)->valores = (*s)->valores->prox;
        free(temp);
    }
    return 0;
}

int size(StackC s) {
    if (!s.valores) return 0;
    StackC temp = {.sp = MAXc, .valores = s->valores->prox};
    return s.sp + size(temp);
}

void reverse (StackC *s) {
    StackC temp = malloc(sizeof(struct stackC));
    temp.sp = 0;
    temp.valores = malloc(sizeof(struct chunk));
    temp.valores->prox = NULL;
    int *x = malloc(sizeof(int));
    while(!pop(s, x)) push(&temp, *x);
    (*s) = temp;
} 



