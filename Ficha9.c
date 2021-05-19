typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d) {
   ABin a = malloc (sizeof(struct nodo));
   if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
   }
return a; }

//1 a
int altura (ABin a) {
    int r = 0; 
    if (a) {
        r++;
        r+=MAX(altura(a->esq), altura(a->dir));
    }
    return r;
}

//1 b
int nFolhas (ABin a) {
    int r = 0;
    if (a) {
        if (!a->esq && !a->dir) r++;
        else r+= nFolhas(a->esq) + nFolhas(a->dir);
    }
    return r;
}

//1 c
ABin maisEsquerda (ABin a) {
    int r = 0;
    if (a) {
        if (a->esq) r = maisEsquerda(a->esq);
        else r = a->esq;
    }
    return r;
}

//1 d
void imprimeNivel (ABin a, int l) {
    if (a) {
        if (!l) {
            printf("%d ", a->valor);
        }
        else {
            imprimeNivel(a->esq, l-1);
            imprimeNivel(a->dir, l-1);
        }
    }
}

//1 e
int procuraE (ABin a, int x) {
    int r = 0;
    if (a) {
        if (a->valor == x) r = 1;
        else {
            r = MAX(procuraE(a->esq), procuraE(a->dir));
        }
    }
    return r;
}

//2
//f
ABin procura (ABin a, int x) {
    ABin res = NULL;
    if (a) {
        if (a->valor == x) res = a;
        else {
            if (x > a->valor) procura(a->dir, x);
            else procura(a->esq, x);
        }
    }
    return r;
}

//g
int nivel (ABin a, int x) {
    int r = -1;
    if (a) {
        if (a->valor == x) r = 0;
        else {
            if (a->valor > x) r = nivel(a->dir, x);
            else r = nivel(a->esq, x);
            if (r != -1) r++;
        }
    }
    return r;
}

//h
void imprimeAte (ABin a, int x) {
    if (a) {
        if (x > a->valor) {
            imprimeAte(a->esq, x);
            printf("%d ", a->valor);
            imprimeAte(a->dir, x);
        }
        else 
            imprimeAte(a->esq, x);
    }
}

