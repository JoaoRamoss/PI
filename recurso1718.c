typedef struct posicao {
int x, y;
} Posicao;

typedef struct slist {
int valor;
struct slist *prox;
} *LInt;

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;

char *strstr (char s1[], char s2[]) {
    char *res = NULL;
    int found = 0;
    for (int i = 0; s1[i]; i++) {
        if (s1[i] == s2[0]) {
            for (int j = 0; s2[j]; j++) {
                if(s1[i+j] != s2[j]) break;
                else found = 1;
            }
            if (found){
                 res = &s1[i];
                 return res;
            }
        }
    }
    return res;
}

void truncW (char t[], int n)  {
    int wordlen = 0;
    int i,k;
    for (i = 0; t[i]; i++) {
        if (t[i] == ' ' || t[i] == '\n' || t[i] == '\t') wordlen = 0;
        else {
            if (wordlen++ >= n) {
                for (k = i; t[k]; k++) t[k] = t[k+1];
                i--;
            }
        }
    }
}

double dist (Posicao p1, Posicao p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int maiscentral (Posicao pos[], int N) {
    Posicao centro;
    int res = -1, i, aux;
    centro.x = centro.y = 0;
    double melhorDist = 10000;

    for (i = 0; i < N; i++) {
        if ((aux = dist(centro, pos[i])) < melhorDist) {
            melhorDist = aux;
            res = i;
        }
    }
    return res;
}

LInt somasAcL (LInt l) {
    int sum = 0;
    LInt lst = NULL, temp = NULL;

    for (; l; l = l->prox) {
        sum += l->valor;
        LInt new = malloc(sizeof(struct lligada));
        new->valor = sum;
        new->prox = NULL;

    }
}

LInt somasACL (LInt l) {
    int sum = 0;
    LInt lst = temp = NULL;

    for (; l; l = l->prox) {
        sum += l->valor;
        LInt new = malloc(sizeof(struct lligada));
        new->valor = sum;
        new->prox = NULL;
        if (!list) list = temp = new;
        else temp = temp->prox = new;
    }
    return list;
}

int addOrd (ABin *a, int x) {
    if (!a) return 0;
    if (a) {
        if (a->valor == x) return 1;
        if (x < a->valor) addOrd(a->esq, x);
        else addOrd(a->dir, x);
    }
    return 0;
}

int daPalavra (char *s, int *e)  {
    for ((*e); s[(*e)] && isspace(s[(*e)]); (*e));
    int len;
    for (len = 0; s[len + (*e)] && !isspace(s[len + (*e)]); len++);
    return len;
}

Palavras words (char *texto) {
    if (!texto) return NULL;
    int e, n; 
    n = daPalavra(texto, &e); 
    if (!n) return NULL;
    Palavras new = malloc(sizeof(struct celula));
    new->palavra = texto + e;
    new->comp = n;
    new->prox = words(texto + n + e);
    return new;
}

 Palavras daLinha (Palavras t, int n) {
     Palavras prev;
     int len = 0;
     for (; len < n && t; t = t->prox) {
         len += t->comp + 1;
         if (len > n) break;
         prev = t;
     }
     t = prev->prox;
     prev->prox = NULL;
     return t;
 }

int tamLinha(Palavras p, int* numP) {
    int len = 0;
    (*numP) = 0;
    while(p) {
        len += p->comp;
        if(p->prox) len++;
        (*numP)++;
        p = p->prox;
    }
    return len;
}

 void escreveLinha (Palavras p, int n) {
     int numP;
     int len = tamLinha(p, &numP);
     if (numP == 1) printf("%s\n", p->palavra);
     else {
         int espacos = n-len;
         while(p) {
             printf("%s", p->palavra);
             numP--;
             if (p->prox) {
                 for (; (espacos/numP) > 0; espacos--) putchar(' ');
             }
             p = p->prox;
         }
     }
 }

void formata (char texto[], int largura) {
    Palavras p = words(texto);
    Palavras resto;
    while(resto = daLinha(p, largura)) {
        escreveLinha(p, largura);
        pals = resto;
    }
    escreveLinha(pals, largura);
}