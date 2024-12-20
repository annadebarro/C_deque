#ifndef PROJ3B_DEQUE_H
#define PROJ3B_DEQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void *data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque {
    Node *front;
    Node *back;
    int count;
} Deque;

// To declare the reqs for the deque print function pointer.
typedef void (*printData)(void *);

Node *newNode(void *data, size_t dataSize);
Deque *createDeque();
void insertFront(Deque *deque, void *data, size_t dataSize);
void insertBack(Deque *deque, void *data, size_t dataSize);
void removeFront(Deque *deque, void *data, size_t dataSize);
void removeBack(Deque *deque, void *data, size_t dataSize);
void freeDeque(Deque *deque);
void printDeque(Deque *deque, void (*printData)(const void *));
void printLong(const void *data);
void printStr(const void *data);
#endif
