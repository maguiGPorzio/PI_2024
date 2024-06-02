#include <stdio.h>
#include <assert.h>
#include "/home/mgonzalezporzio/PI/taller11_02.h"
 
int
main(void) {
    queueADT q = newQueue();
    queue(q, 5);
    queue(q, 9);
    queue(q, 3);
    int aux;
    dequeue(q, &aux);
    assert(aux == 5);
    dequeue(q, &aux);
    assert(aux == 9);
    queue(q, 1);
    dequeue(q, &aux);
    assert(aux == 3);
    dequeue(q, &aux);
    assert(aux == 1);
    assert(isEmpty(q) == 1);
    freeQueue(q);

    q = newQueue();
    queue(q, 5);
    queue(q, 9);
    queue(q, 3);
    toBegin(q);
    while (hasNext(q)) { // 5 9 3
        printf("%d ", next(q));
    }

    freeQueue(q);
    printf("OK!\n");
    return 0;
}