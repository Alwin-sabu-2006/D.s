#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(char* url) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void visitPage(struct Node** current, char* url) {
    struct Node* newNode = createNode(url);

    if (*current != NULL) {
        struct Node* temp = (*current)->next;
        while (temp != NULL) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
        (*current)->next = newNode;
        newNode->prev = *current;
    }
    *current = newNode;
    printf("Visited: %s\n", url);
}

void goBack(struct Node** current) {
    if (*current && (*current)->prev) {
        *current = (*current)->prev;
        printf("Back to: %s\n", (*current)->url);
    } else {
        printf("No previous page.\n");
    }
}
void goForward(struct Node** current) {
    if (*current && (*current)->next) {
        *current = (*current)->next;
        printf("Forward to: %s\n", (*current)->url);
    } else {
        printf("No forward page.\n");
    }
}

void showCurrentPage(struct Node* current) {
    if (current) {
        printf("Current page: %s\n", current->url);
    } else {
        printf("No page visited.\n");
    }
}

int main() {
    struct Node* current = NULL;
    char input[100];
    int choice;

    while (1) {
        printf("\n1. Visit new page\n2. Go Back\n3. Go Forward\n4. Show Current Page\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;  
                visitPage(&current, input);
                break;
            case 2:
                goBack(&current);
                break;
            case 3:
                goForward(&current);
                break;
            case 4:
                showCurrentPage(current);
                break;
            case 5:
                printf("Exiting...\n");
                
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
