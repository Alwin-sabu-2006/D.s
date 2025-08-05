#include <stdio.h>
#define size 10

int que[size];
int front = -1, rear = -1;

void Insert_front(int value) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Overflow\n");
    } else {
        if (front == -1) { 
            front = rear = 0;
        } else if (front > 0) {
            front--;
        } else {
            printf("Cannot insert at front\n");
            return;
        }
        que[front] = value;
        printf("Succesfully added at the front");
    }
}

void Insert_back(int value) {
    if (rear == size - 1) {
        printf("Overflow\n");
    } else {
        if (front == -1) { 
            front = rear = 0;
        } else {
            rear++;
        }
        que[rear] = value;
        printf("Succesfully added athe back");
    }
}

void delete_front() {
    if (front == -1) {
        printf("Underflow\n");
    } else {
        int item = que[front];
        printf("Deleted from front: %d\n", item);
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
}

void delete_back() {
    if (rear == -1) {
        printf("Underflow\n");
    } else {
        int item = que[rear];
        printf("Deleted from back: %d\n", item);

        for (int i = front; i <= rear; i++) {
            printf("%d ", que[i]);
        }
        printf("\n");
    }
}
void display() {
    if (front == -1 || front > rear) {
        printf("Deque is empty\n");
    } else {
        printf("Deque elements:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", que[i]);
        }
        printf("\n");
    }
}
int main() {
    int n, value;
    while (1) {
        printf("\n1. Insert Front\n2. Insert Back\n3. Delete Front\n4. Delete Back\n5. Display\n6. Exit");
        printf("\nEnter the operation number: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("Enter the value to insert at front: ");
                scanf("%d", &value);
                Insert_front(value);
                break;
            case 2:
                printf("Enter the value to insert at back: ");
                scanf("%d", &value);
                Insert_back(value);
                break;
            case 3:
                delete_front();
                break;
            case 4:
                delete_back();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid Entry\n");
        }
    }
    return 0;
}
