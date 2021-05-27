char *strcat (char s1[], char s2[]) {
    int i, j;
    for (i = 0; s1[i]; i++);
    for (j = 0; s2[j]; j++, i++) s1[i] = s2[j];
    s1[i] = 0;
    return s1;
}

int remRep (char x[]) {
    int i, j;
    int len;
    for(len = 0; x[len]; len++);
    for (i = 1; x[i]; i++) {
        if (x[i-1] == x[i]) {
            for (j = i; x[j]; j++) 
                x[j] = x[j+1];
            i--;
            len--;
        }
    }
    return len;
}

typedef struct nodo {
   int valor;
   struct nodo *esq, *dir;
} *ABin;

int nivelV (ABin a, int n, int v[]) {
    if (!a || n < 1) return 0;

    if (n == 1)
        *v = a->valor;
        return 1;
    else {
        int e = nivelV(a->esq, n-1, v);
        int d = nivelV(a->dir, n-1, v+e);
        return e + d;
    }
}

int addOrd (ABin *a, int x) {
    if (!*a) {
        ABin aux = malloc(sizeof(struct nodo));
        aux->valor = x;
        aux->esq = aux->dir = NULL;
        *a = aux;
        return 0;
    }
    if ((*a)->valor == x) return 1;
    if ((*a)->valor > x) addOrd(&((*a)->esq), x);
    else addOrd(&((*a)->dir), x);
}

int addOrd (ABin *a, int x) {
    while (*a) {
        if ((*a)->valor == x) return 1;
        else if ((*a->valor) < x) a = &((*a)->dir);
        else a = &((*a)->esq);
    }
    if (!*a) {
        Abin help = malloc(sizeof(struct nodo));
        help->valor = x;
        help->esq = help->dir = NULL;
        *a = help;
    }
    return 0;
}

//Parte B------------------

typedef struct listaC {
   int coluna;
   float valor;
   struct listaC *prox;
   } *Colunas;

   typedef struct listaL {
   int linha;
   Colunas lcol;
   struct listaL *prox;
} *Mat;

float getEntry (Mat m, int linha, int coluna) {
    if (!m) return 0;
    while (m) {
        if (m->linha == linha) {
            while (m->lcol) {
                if (m->lcol->coluna == coluna) return m->lcol->valor;
                m->lcol = m->lcol->prox;
            }
        }
        m = m->prox;
    }
    return 0;
}

void setEntry (Mat *m, int linha, int coluna, float valor) {
    if (!*m) {
        Mat aux = malloc(sizeof(struct listaL));
        aux->linha = linha;
        aux->lcol = malloc(sizeof(struct listaC));
        aux->lcol->coluna = coluna;
        aux->lcol->valor = valor;
        aux->lcol->prox = NULL;
        aux->prox = NULL;
    }
    for (int i = 0; i < linha && *m; i++) 
        m = &((*m)->prox);

    for (int j = 0; i < coluna && (*m)->lcol; j++)
        (*m)->lcol = (*m)->lcol->prox;

    (*m)->lcol->valor = valor; 
}

void addTo (Mat *m1, Mat m2) {
    if (*m1 && m2) {
        while (*m1 && m2) {
            while((*m1)->lcol && m2->lcol) {
                m2->lcol->valor += (*m1)->lcol->valor;
                m2->lcol = m2->lcol->prox;
                (*m1)->lcol = (*m1)->lcol->prox;
            }
            m1 = &((*m1)->prox);
            m2 = m2->prox;
        }
    }
}

void transpose (Mat *m) {
    
}
