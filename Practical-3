#include <stdio.h>
#include <conio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = val;
    printf("%d pushed\n", val);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped\n", stack[top]);
    top--;
}

void peep() {
    int i;
    printf("Enter position from top (1 = top): ");
    scanf("%d", &i);
    if (i < 1 || top - i + 1 < 0) {
        printf("Invalid position\n");
        return;
    }
    printf("Value at position %d: %d\n", i, stack[top - i + 1]);
}

void change() {
    int i, val;
    printf("Enter position from top (1 = top): ");
    scanf("%d", &i);
    if (i < 1 || top - i + 1 < 0) {
        printf("Invalid position\n");
        return;
    }
    printf("Enter new value: ");
    scanf("%d", &val);
    stack[top - i + 1] = val;
    printf("Value changed\n");
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom):\n");
    for (i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

void main() {
    int choice, val;
    clrscr();
    do {
        printf("\n1.PUSH 2.POP 3.PEEP 4.CHANGE 5.DISPLAY 6.EXIT\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peep();
                break;
            case 4:
                change();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);
    getch();
}
