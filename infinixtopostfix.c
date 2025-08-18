#include <stdio.h>
#define MAX 100
#include <ctype.h>

char stack[MAX];
int top = -1;

void push(char c) 
{
    stack[++top] = c;
}

char pop() {
    if (top == -1) 
    {
        return '\0';
    } 
    else 
    {
        return stack[top--];
    }
}

char peek() {
    if (top == -1) 
    {
        return '\0';
    } else {
        return stack[top];
    }
}

int precedence(char c) {
    if (c == '^') 
    {
        return 3;
    } 
    else if (c == '*' || c == '/') 
    {
        return 2;
    }
     else if (c == '+' || c == '-') 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

int isOperator(char c) {
    if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-') {
        return 1;
    } else {
        return 0;
    }
}

void infinixtopostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char c;

    while ((c = infix[i]) != '\0') {
       
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            postfix[j++] = c;
        }
        else if(isdigit(c)){
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            if (peek() == '(') {
                pop();  
            }
        }
        else if (isOperator(c)) {
            while (top != -1 && isOperator(peek()) && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
        i++;
    }
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infinixtopostfix(infix, postfix);
    printf("The postfix expression is: %s\n", postfix);
    return 0;
}
