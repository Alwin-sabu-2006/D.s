#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100


char stack_op[MAX];
int top_op = -1;

void push_op(char c) {
    stack_op[++top_op] = c;
}

char pop_op() {
    return stack_op[top_op--];
}

char peek_op() {
    return stack_op[top_op];
}

int isEmpty_op() {
    return top_op == -1;
}

int precedence(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int i, k=0;
    char c;
    for(i = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        if(isalnum(c)) {
            postfix[k++] = c;
        } else if(c == '(') {
            push_op(c);
        } else if(c == ')') {
            while(!isEmpty_op() && peek_op() != '(') {
                postfix[k++] = pop_op();
            }
            pop_op(); 
        } else { 
            while(!isEmpty_op() && precedence(peek_op()) >= precedence(c)) {
                postfix[k++] = pop_op();
            }
            push_op(c);
        }
    }
    while(!isEmpty_op()) {
        postfix[k++] = pop_op();
    }
    postfix[k] = '\0';
}
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct StackNode {
    Node* treeNode;
    struct StackNode* next;
} StackNode;


StackNode* top_tree = NULL;

void push_tree(Node* node) {
    StackNode* newNode = (StackNode*) malloc(sizeof(StackNode));
    newNode->treeNode = node;
    newNode->next = top_tree;
    top_tree = newNode;
}

Node* pop_tree() {
    if(top_tree == NULL) return NULL;
    StackNode* temp = top_tree;
    Node* res = temp->treeNode;
    top_tree = top_tree->next;
    free(temp);
    return res;
}

Node* createNode(char c) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = c;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree(char* postfix) {
    int i;
    char c;
    for(i = 0; postfix[i] != '\0'; i++) {
        c = postfix[i];
        if(isalnum(c)) {
            push_tree(createNode(c));
        } else { // operator
            Node* right = pop_tree();
            Node* left = pop_tree();
            Node* node = createNode(c);
            node->left = left;
            node->right = right;
            push_tree(node);
        }
    }
    return pop_tree();
}


void preorder(Node* root) {
    if(root == NULL) return;
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    Node* root = buildTree(postfix);

    printf("Prefix: ");
    preorder(root);
    printf("\n");

    printf("Postfix: ");
    postorder(root);
    printf("\n");

    return 0;
}

