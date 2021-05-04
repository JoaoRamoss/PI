#include <stdio.h>
#include <stdlib.h>
#define Max 10

typedef struct staticStack {
       int sp;
       int values [Max];
     } STACK, *SStack;

void SinitStack (SStack s) {
    s = calloc(1, sizeof(struct staticStack));    
}

int SisEmpty (SStack s) {
    int a = 0;
    if (s->sp == 0) a = 1;
    else if (s->sp != 1) a = 0;
    return a;    
}

int Spush (SStack s, int x) {
    if (s->sp == Max) return 1;
    else {
        s->values[s->sp] = x;
        s->sp++;
    }
    return 0;
}

int Spop (SStack s, int *x) {
    if (s->sp > 0) {
        s->sp--;
        *x = s->values[s->sp];
        return 0;
    }
    else return 1;
}

int Stop (SStack s, int *x) {
    if (s->sp > 0) {
        *x = s->values[s->sp-1];
        return 0;
    }
    else return 1;
}

// -------------- *** ------------------- *** ----------------- //

typedef struct staticQueue {
    int front;
    int length;
    int values [Max];
  } QUEUE, *SQueue;

void SinitQueue (SQueue q) {
    q = calloc(1, sizeof(struct staticQueue));
}

SisEmptyQ (SQueue q) {
    if (q->length == 0) return 1;
    else return 0;
}

int Senqueue (SQueue q, int x) {
    if (q->length < Max) {
        q->values[(q->front + q->length)%Max] = x;
        q->length++;
        return 0;
    }
    else return 1;
}

int Sdequeue (SQueue q, int *x) {
    if (q->length > 0) {
        *x = q->values[q->front];
        q->front = (q->front+1)%Max;
        q->length--;
        return 0;
    }
    else return 1;
}

int Sfront (SQueue q, int *x) {
    if (q->length > 0) {
        *x = q->values[q->front];
        return 0;
    }
    else return 1;
}

// ---------- *** ------------- *** ----------- //

typedef struct dinStack {
    int size; // guarda o tamanho do array values
    int sp;
    int *values;
} *DStack;

  typedef struct dinQueue {
    int size; // guarda o tamanho do array values
    int front;
    int length;
    int *values;
} *DQueue;

void DinitStack (DStack ds) {
    ds->size = Max;
    ds->sp = 0;
    ds->values = calloc(ds->size, sizeof(int));
}

int dupStack(DStack s){
    int r=1, i;
    int *t = malloc(sizeof(int)*2*s->size);
    if(t!=NULL){
        for(i=0;i<s->size;i++) t[i] = s->values[i];
        free(s->values);
        s->values = t;
        s->size*=2;
    }
    return r;
}

int DisEmpty (DStack ds) {
    if (ds->sp == 0) return 1;
    else return 0;
}

int Dpush(DStack s, int x){
    int r=0;
    if(s->sp == s->size) r = dupStack(s);
    if(r==0) s->values[s->sp++] = x;
    return r;
}

int  Dpop (DStack s, int *x){
    int r=0;
    
    return r;
}