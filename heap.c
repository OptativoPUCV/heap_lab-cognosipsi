#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
    if (pq->size == pq->capac) {
        pq->capac = pq->capac * 2 + 1;
        pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));
    }
    int actual = pq->size;
    while (actual > 0 && pq->heapArray[(actual-1)/2].priority < priority) {
        pq->heapArray[actual] = pq->heapArray[(actual-1)/2];
        actual = (actual-1)/2;
    }
    pq->heapArray[actual].priority = priority;
    pq->heapArray[actual].data = data;
    pq->size++;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
    Heap *h = (Heap*) malloc (sizeof(Heap));
    h->size = 0;
    h->capac = 3;
    h->heapArray = realloc (h->heapArray, h->capac);
    /*h->heapArray[h->size].priority = 1;
    h->heapArray[h->size].data = NULL;*/

    return h;
}
