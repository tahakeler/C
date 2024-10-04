// modified for SEN-107 Lab 2 by Taha
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_TAXI_CAPACITY 5

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} PassengerNode;

typedef struct Queue {
    PassengerNode* front;
    PassengerNode* rear;
    int size;
} PassengerQueue;

typedef struct TaxiNode {
    int registrationNumber;
    struct TaxiNode* next;
} TaxiNode;

typedef struct TaxiQueue {
    TaxiNode* front;
    TaxiNode* rear;
    int size;
} TaxiQueue;

// Creating a passenger Queue
PassengerQueue* createPassengerQueue() {
    PassengerQueue* q = (PassengerQueue*)malloc(sizeof(PassengerQueue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

// Passenger queue size
int isPassengerQueueEmpty(PassengerQueue* q) {
    return q->size == 0;
}

void enqueuePassenger(PassengerQueue* q, const char* name) {
    PassengerNode* newNode = (PassengerNode*)malloc(sizeof(PassengerNode));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

PassengerNode* dequeuePassenger(PassengerQueue* q) {
    if (isPassengerQueueEmpty(q)) {
        return NULL;
    }
    PassengerNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    q->size--;
    return temp;
}

void freePassengerQueue(PassengerQueue* q) {
    PassengerNode* current = q->front;
    while (current != NULL) {
        PassengerNode* next = current->next;
        free(current);
        current = next;
    }
    free(q);
}

TaxiQueue* createTaxiQueue() {
    TaxiQueue* q = (TaxiQueue*)malloc(sizeof(TaxiQueue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

int isTaxiQueueEmpty(TaxiQueue* q) {
    return q->size == 0;
}

void enqueueTaxi(TaxiQueue* q, int registrationNumber) {
    TaxiNode* newNode = (TaxiNode*)malloc(sizeof(TaxiNode));
    newNode->registrationNumber = registrationNumber;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

TaxiNode* dequeueTaxi(TaxiQueue* q) {
    if (isTaxiQueueEmpty(q)) {
        return NULL;
    }
    TaxiNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    q->size--;
    return temp;
}

void freeTaxiQueue(TaxiQueue* q) {
    TaxiNode* current = q->front;
    while (current != NULL) {
        TaxiNode* next = current->next;
        free(current);
        current = next;
    }
    free(q);
}

int main() {
    PassengerQueue* passengerQueue = createPassengerQueue();
    TaxiQueue* taxiQueue = createTaxiQueue();
    int choice;
    char name[MAX_NAME_LENGTH];
    int taxiRegistrationNumber;
    PassengerNode* group;
    int totalPassengerGroupsServed = 0;
    int totalPassengerGroupsWaiting = 0;

    while (1) {
        printf("\nAirport Taxi Events:\n");
        printf("1 - New group of passengers arrived\n");
        printf("2 - New taxi arrived\n");
        printf("3 - Exit program\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the names of the group members (up to %d):\n", MAX_TAXI_CAPACITY);
                for (int i = 0; i < MAX_TAXI_CAPACITY; i++) {
                    scanf("%s", name);
                    if (strcmp(name, "#") == 0) {
                        break;
                    }
                    enqueuePassenger(passengerQueue, name);
                }
                if (isTaxiQueueEmpty(taxiQueue)) {
                    printf(">> Successfully added passenger group to taxi queue\n");
                } else {
                    printf(">> New taxi given to waiting passenger group: ");
                    group = dequeuePassenger(passengerQueue);
                    while (group != NULL) {
                        printf("%s, ", group->name);
                        totalPassengerGroupsServed++;
                        free(group);
                        group = dequeuePassenger(passengerQueue);
                    }
                    printf("\n");
                }
                break;

            case 2:
                if (isPassengerQueueEmpty(passengerQueue)) {
                    printf(">> There are no passenger groups waiting in the queue\n");
                    enqueueTaxi(taxiQueue, taxiRegistrationNumber);
                } else {
                    printf(">> New taxi given to waiting passenger group: ");
                    group = dequeuePassenger(passengerQueue);
                    while (group != NULL) {
                        printf("%s, ", group->name);
                    }
                }
        }
    }

    return qsort_r;
}