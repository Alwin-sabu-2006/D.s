#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

// Function to initialize hash table
void initialize() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;   // -1 means empty slot
}

// Function to insert elements using linear probing
void insert(int key) {
    int index = key % SIZE;
    int i = index;

    // Linear probing if collision occurs
    while (hashTable[i] != -1) {
        i = (i + 1) % SIZE;
        if (i == index) {
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }
    hashTable[i] = key;
}

// Function to display hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d --> %d\n", i, hashTable[i]);
        else
            printf("Index %d --> EMPTY\n", i);
    }
}

int main() {
    int n, key;

    initialize();

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
