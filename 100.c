typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

//1
int length (LInt l) {
    int res = 0;
    while (l != NULL) {
        res++;
        l = l->prox;
    }
    return res;
}

//2
void freeL (LInt l) {
    LInt aux;
    while (l != NULL) {
        aux = l;
        l = l->prox;
        free(aux);
    }
}

//3
void imprimeL (LInt l) {
    while (l) {
        printf("%d\n", l->valor);
        l = l->prox;
    }
} 

//4
LInt reverseL(LInt l) {
    LInt prev, current, next;
    prev = NULL;
    current = l;
    
    while (current != NULL) {
        next = current->prox;
        current->prox = prev;
        prev = current;
        current = next;
    }
    l = prev;
    return l;
}

//5
void insertOrd (LInt* l, int x) {
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    LInt prev = NULL;
    for(;*l && (*l)->valor < x; prev = (*l), l = &((*l)->prox));
    if(prev) {
        new->prox = (*l);
        prev->prox = new;
    }
    else {
        new->prox = (*l);
        *l = new;
    }
}

//6
int removeOneOrd (LInt *l, int x) {
    LInt prev = NULL;
    for (; (*l) && x != (*l)->valor; prev = *l, l = &((*l)->prox));
    if (!(*l)) return 1;
    if (!prev) (*l) = ((*l)->prox);
    else prev->prox = (*l)->prox;
    return 0;
}

//7
void merge (LInt *r, LInt a, LInt b) {
    if (!a && !b) return;
    if (!b || a && a->valor < b->valor) {
        (*r) = a;
        merge(&(*r)->prox, a->prox, b);
    }
    else {
        (*r) = b;
        merge(&(*r)->prox, a, b->prox);
    }
}

//8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx) {
    if (!l) return 0;
    if (l->valor < x) {
        (*mx) = l;
        (*Mx) = NULL;
        splitQS(l->prox, x, &((*mx)->prox), Mx);
    }
    else {
        (*Mx) = l;
        (*mx) = NULL;
        splitQS(l->prox, x, mx, &((*Mx)->prox));
    }
}

//9
LInt parteAmeio (LInt *l) {
    int meio = length(*l)/2;
    if (meio == 0) return NULL;
    LInt y = (*l);
    LInt prev = NULL;
    for (i = 0; i < meio; i++) {
        prev = (*l);
        (*l) = (*l)->prox;
    }
    prev->prox = NULL;
    return y;
}

//10
int removeAll (LInt *l , int x) {
    int res = 0;
    LInt prev = NULL;
    while ((*l)) {
        if ((*l)->valor == x) {
            if (!prev) (*l) = (*l)->prox;
            else prev->prox = (*l)->prox;
            res++;
        }
        else {
            prev = (*l);
            l = &((*l)->prox);
        }
    }
    return res;
}

//11
 int removeDups (LInt *l) {
     int res = 0;
     for (; *l; l = &((*l)->prox)) {
         LInt prev = (*l), aux = ((*l)->prox);
         for (; aux; aux = prev->prox) {
             if (aux->valor == (*l)->valor) {
                 prev->prox = aux->prox;
                 res++;
                 free(aux);
             }
             else prev = aux;
         }
     }
     return res;
 }

//12
int removeMaiorL (LInt *) {
    int max = (*l)->valor;
    LInt prev = NULL;
    LInt maxPrev = NULL;
    LInt maxL = (*l);
    LInt list = (*l);

    for (;list; list = list->prox) {
        if (list->valor > max) {
            maxPrev = prev;
            maxL = list;
            max = list->valor;
        }
        prev = list;
    }
    if (!maxPrev) (*l) = (*l)->prox;
    else maxPrev->prox = maxL->prox;
    return max;
}

//13
void init (LInt *l) {
    LInt prev = NULL;
    for (;(*l)->prox;prev = *l, l = &((*l)->prox)); //Coloca (*l) no último elemento.
    
    free(*l);
    *l = NULL; //<Opcional> Set apontador para NULL para prevenir erros (pelo que diz no stack overflow xD)
}

//14
void appendL (LInt *l, int x) {
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    if (!(*l)) (*l) = new;
    else {
        for (;(*l)->prox; l = &((*l)->prox));
        (*l)->prox = new;
    }
}

//15
void concatL (LInt *a, LInt b) {
    for (;(*a); a = &((*a)->prox));
    (*a) = b;
}

//16
LInt cloneL (LInt l) {
    if (!l) return NULL;
    LInt new = malloc(sizeof(struct lligada));
    new->valor = l->valor;
    new->prox = cloneL(l->prox);
    return new;
}

//17
LInt cloneRev (LInt l) {
    if (!l) return NULL;
    int len = length(l), i;
    LInt array[len];
    for (i = len - 1; i >= 0; i--) {
        array[i] = malloc(sizeof(struct lligada));
        array[i]->valor = l->valor;
        if (i < len - 1) array[i]->prox = array[i+1];
        else array[i]->prox = NULL;
        l = l->prox;
    }
    return array;
}

//18 #inlude <limits.h>
int maximo (LInt l) {
    if (!l) return 0;
    int max = INT_MIN;
    while (l) {
        max = l->valor > max ? l->valor : max;
        l = l->prox;
    }
    return max;
}

//19
int take (int n, LInt *l) {
    int i;
    for (i = 0; i < n && *l; i++, l = &((*l)->prox));
    if (!(*l)) return i;
    while (*l) {
        LInt aux = (*l)->prox;
        free(*l);
        *l = NULL;
        *l = aux;
    }
    return n;
}

//20
int drop (int n, LInt *l) {
    int i;
    for (i = 0; i < n && *l;i ++) {
        LInt aux = (*l)->prox;
        free(*l);
        *l = NULL;
        *l = aux;
    }
    return i;
}

//21
LInt Nforward (LInt l, int N) {
    int i;
    for (i = 0; i < N; i++) 
        l = l->prox;
    return l;
}

//22
int listToArray (LInt l, int v[], int N) {
    int i;
    for (i = 0; i < N && l; i++, l = l->prox) v[i] = l->valor;
    return i;
}

//23
LInt arrayToList (int v[], int N) {
    if (N == 0) return NULL;
    LInt new = malloc(sizeof(lligada));
    new->valor = (*v);
    new->prox = arrayToList(v+1, N-1);
    return new;
}

//24
LInt somasAcL (LInt l) {
    int res = 0;
    LInt list = NULL, temp = NULL;
    for (; l; l = l->prox) {
        res += l->valor;
        LInt new = malloc(sizeof(struct lligada));
        new->valor = res;
        new->prox = NULL;
        if (!list) list = temp = new;
        else temp = temp->prox = new;
    }
    return list;
    
}

//25
void remreps (LInt l) {
    if (l) {
        while(l->prox) {
            if (l->prox->valor == l->valor) {
                LInt aux = l->prox;
                l->prox = aux->prox;
                free(aux);
                aux = NULL;
            }
            else l = l->prox;
        }
    }
}


