#include "pqueue.jsdrisco.h"
#include <stdlib.h>
#include <stdio.h>

int enqueue(PQueueNode **pqueue, int priority, void *data) {
    // Case: pqueue is empty. Initialize it.
    if(*pqueue == NULL) {
        *pqueue = malloc(sizeof(PQueueNode));
        (*pqueue)->priority = priority;
        (*pqueue)->data = data;
        (*pqueue)->next = NULL;
    }

        // Case: beginning of list has lower priority than input
    else if((*pqueue)->priority > priority){
        // Create a new node, identical to pqueue
        PQueueNode *node = malloc(sizeof(PQueueNode));
        node->priority = (*pqueue)->priority;
        node->data = (*pqueue)->data;
        node->next = (*pqueue)->next;

        (*pqueue)->priority = priority;
        (*pqueue)->data = data;
        (*pqueue)->next = node;
    }

        // Case: insert somewhere in the middle to the end
    else if((*pqueue)->priority <= priority) {
        // Continue until the next node in the queue is null (end) or has lower priority than input
        PQueueNode *temp = *pqueue;
        while(temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }

        PQueueNode *node = malloc(sizeof(PQueueNode));
        node->priority = priority;
        node->data = data;
        node->next = temp->next;

        temp->next = node;
    }

    return 0;
}


void *dequeue(PQueueNode **pqueue) {
    // Create return variable
    void *returnData;

    // If the list is empty, return NULL
    if((*pqueue) == NULL) {
        return NULL;
    }

        // Otherwise, gather its data, free it from memory, and set it to the next variable.
    else {
        returnData = (*pqueue)->data;
        PQueueNode *temp = (*pqueue)->next;
        free(*pqueue);
        (*pqueue) = temp;
    }

    return returnData;
}

void *peek(PQueueNode *pqueue) {
    // Return NULL if pqueue empty, otherwise return contained data without dequeueing
    if(pqueue == NULL) {
        return NULL;
    }

    return pqueue->data;
}

void printQueue(PQueueNode *pqueue, void (printFunction) (void *)) {
    // Run through the queue and print its values using a specified print function
    PQueueNode *temp = pqueue;
    while(temp != NULL) {
        printf("priority = %u data = ", temp->priority);
        printFunction(temp->data);
        temp = temp->next;
    }
}

int getMinPriority(PQueueNode *pqueue) {
    // If queue is empty, return -1. Otherwise, return lowest priority.
    if(pqueue == NULL) {
        return -1;
    }

    return pqueue->priority;
}

int queueLength(PQueueNode *pqueue) {
    // Set counter to 0, initialize temporary variable.
    int length = 0;
    PQueueNode *temp = pqueue;

    // Run through until NULL pointer reached.
    while(temp != NULL) {
        length++;
        temp = temp->next;
    }

    return length;
}

void printThing(void *data) {
    Thing *t = (Thing *) data;
    printf("\"%s\" (%u lbs)\n", t->name, t->weight);
}
