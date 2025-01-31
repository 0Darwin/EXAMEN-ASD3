#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define MAX 50

int precedence(char operation) {
    if (operation == '+' || operation == '-') return 1;
    if (operation == '*' || operation == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initStack(&stack, MAX);
    int j = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        
       if (isdigit(ch)) 
            postfix[j++] = ch;
       else if (ch == '(') 
            push(&stack, ch);
       else if (ch == ')') {
            while (!is_empty(&stack) && peek(&stack) != '(') 
                postfix[j++] = pop(&stack);
            pop(&stack);
       } else {
            while (!is_empty(&stack) && precedence(peek(&stack)) >= precedence(ch)) 
                postfix[j++] = pop(&stack);
            push(&stack, ch);
        }
    }

    while (!is_empty(&stack)) 
        postfix[j++] = pop(&stack);

    postfix[j] = '\0';
}

int evaluatePostfix(char* postfix) {
    Stack stack;
    initStack(&stack, MAX);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) 
            push(&stack, ch - '0');
        else {
            int b = pop(&stack);
            int a = pop(&stack);
            int result = 0;

            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an arithmetic expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix notation: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}