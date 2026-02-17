// Question2/Student.c
// ------------------------------------------------------------
// CS Lab - Design Circular Queue (RING BUFFER / QUEUE PRACTICE)
//
// Task:
// Implement the circular queue functions declared in student.h.
//
// ------------------------------------------------------------

#include "student.h"
#include <stdlib.h>   // malloc, free

MyCircularQueue* myCircularQueueCreate(int k) {
    if (k <= 0) return NULL;

    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (!q) return NULL;

    q->data = (int*)malloc(sizeof(int) * (size_t)k);
    if (!q->data) {
        free(q);
        return NULL;
    }

    q->capacity = k;
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj == NULL) return false;
    if (obj->size == obj->capacity) return false; // full

    obj->data[obj->tail] = value;
    obj->tail = (obj->tail + 1) % obj->capacity;
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj == NULL) return false;
    if (obj->size == 0) return false; // empty

    obj->head = (obj->head + 1) % obj->capacity;
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj == NULL) return -1;
    if (obj->size == 0) return -1;
    return obj->data[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj == NULL) return -1;
    if (obj->size == 0) return -1;

    int last = (obj->tail - 1 + obj->capacity) % obj->capacity;
    return obj->data[last];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj == NULL) return true;
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if (obj == NULL) return false;
    return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if (obj == NULL) return;
    free(obj->data);
    free(obj);
}
