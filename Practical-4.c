#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void main() {
    char infix[MAX], postfix[MAX], ch;
    int i, j = 0;

    clrscr();
    printf("Enter infix expression (no spaces): ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
    getch();
}
