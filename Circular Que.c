#include <stdio.h>
#define size 10

int que[size];
int front = -1, rear = -1,i=0;

void enqueue(int value) {
    if ((rear+1)%size==front) {
        printf("Overflow\n");
    } 
    else if (front == -1 && rear==-1) {
            front = rear=0; 
        
        que[rear] = value;
        printf("Successfully added ");
    }
    else {
        rear=(rear+1)%size;
        que[rear]=value;    }
    }


void dequeue() {
    if (front == -1 && rear==-1) {
        printf("queue is empty\n");
    } else if (front==rear)
    {
        printf("Deleted item is %d",que[front]);
        front=rear-1;
    }
    else{
        printf("Deleted item is %d",que[front]);
        front=(front+1)%size;
    }
}
void display() {
    if (front == -1 && rear==-1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
          while (1) {
            printf("%d\n", que[i]);
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
    }
}

int main() {
    int n, value;
    while (1) {
        printf("\n1. Add\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter the number of the operation you want to perform: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("Enter the value to be added: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid Entry\n");
        }
    }
}
