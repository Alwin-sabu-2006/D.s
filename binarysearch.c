#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int key) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        printf("Key %d already exists. Skipping insert.\n", key);

    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}


Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Found node to delete
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, key;

    printf("Binary Search Tree operations:\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Inorder traversal\n5. Exit\n");
        printf("Enter your choice: ");
        if(scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter number to insert: ");
                if(scanf("%d", &key) != 1) {
                    printf("Invalid input.\n");
                    // Clear input buffer
                    while(getchar() != '\n');
                    break;
                }
                root = insert(root, key);
                printf("%d inserted.\n", key);
                break;

            case 2:
                printf("Enter number to search: ");
                if(scanf("%d", &key) != 1) {
                    printf("Invalid input.\n");
                    while(getchar() != '\n');
                    break;
                }
                Node* found = search(root, key);
                if (found)
                    printf("Key %d found in BST.\n", key);
                else
                    printf("Key %d not found.\n", key);
                break;

            case 3:
                printf("Enter number to delete: ");
                if(scanf("%d", &key) != 1) {
                    printf("Invalid input.\n");
                    while(getchar() != '\n');
                    break;
                }
                root = deleteNode(root, key);
                printf("If key existed, %d deleted.\n", key);
                break;

            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
