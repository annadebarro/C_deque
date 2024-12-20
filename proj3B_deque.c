#include "proj3B_deque.h"

Node *newNode(void *data, size_t dataSize) {
   Node *aNode = (Node*)malloc(sizeof(Node));

   if(aNode == NULL) {
       fprintf(stderr, "Error allocating memory for node.\n");
       exit(EXIT_FAILURE);
   }

   aNode->data = malloc(dataSize);
   if(aNode->data == NULL) {
       fprintf(stderr, "Error allocating memory for node data.\n");
       free(aNode);
       exit(EXIT_FAILURE);
   }

   memcpy(aNode->data, data, dataSize);

   aNode->next = NULL;
   aNode->prev = NULL;

   return aNode;
}

Deque *createDeque() {
   Deque *aDeque = (Deque*)malloc(sizeof(Deque));

   if(aDeque == NULL) {
       fprintf(stderr, "Error allocating memory for deque.\n");
       exit(EXIT_FAILURE);
   }

   aDeque->front = NULL;
   aDeque->back = NULL;
   aDeque->count = 0;

   return aDeque;
}

void insertFront(Deque *deque, void *data, size_t dataSize) {
    Node *aNode = newNode(data, dataSize);

    if(deque->front == NULL) {
        deque->front = aNode;
	deque->back = aNode;
    }
    else {
        aNode->next = deque->front; // New node next points to current front
	deque->front->prev = aNode; // deque front prev pointer points to new node
	deque->front = aNode;
    }
    deque->count++;
}

void insertBack(Deque *deque, void *data, size_t dataSize) {
    Node *aNode = newNode(data, dataSize);

    if(deque->front == NULL) {
        deque->front = aNode;
	deque->back = aNode;
    }
    else {
        aNode->prev = deque->back;
	deque->back->next = aNode;
	deque->back = aNode;
    }
    deque->count++;
}

void removeFront(Deque *deque, void *data, size_t dataSize) {
   if(deque->front == NULL) {
       fprintf(stderr, "Deque is empty.\n");
       return;
   }
   memcpy(data, deque->front->data, dataSize);
   Node *temp = deque->front;
   deque->front = deque->front->next;

   if(deque->front == NULL) {
       deque->back = NULL;
   }
   else {
       deque->front->prev = NULL;
   }

   free(temp->data);
   free(temp);
   deque->count--;
}

void removeBack(Deque *deque, void *data, size_t dataSize) {
    if(deque->back == NULL) {
        fprintf(stderr, "Deque is empty.\n");
	return;
    }
    memcpy(data, deque->back->data, dataSize);
    Node *temp = deque->back;
    deque->back = deque->back->prev;

    if(deque->back == NULL) {
        deque->front = NULL;
    }
    else {
        deque->back->next = NULL;
    }

    free(temp->data);
    free(temp);
    deque->count--;
}

void freeDeque(Deque *deque) {
    while(deque->front != NULL) {
        Node *temp = deque->front;
	deque->front = deque->front->next;
	free(temp->data);
	free(temp);
    }
    free(deque);
}

void printDeque(Deque *deque, void (*printData)(const void*)) {
    Node *temp = deque->front;

    while(temp != NULL) {
        printData(temp->data);
	temp = temp->next;
    }
    printf("\n");
}

// Functions for printing

void printLong(const void *data) {
    const long *numData = (const long*)data;
    printf("%ld ", *numData);
}

void printStr(const void *data) {
    const char *strData = (const char*)data;
    printf("%s ", strData);
}
