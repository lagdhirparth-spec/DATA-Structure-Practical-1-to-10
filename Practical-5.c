#include <stdio.h>
#include <conio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert(int val) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = val;
    printf("%d inserted\n", val);
}

void delete_item() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d deleted\n", queue[front]);
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

void show_front() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front item: %d\n", queue[front]);
}

void show_rear() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Rear item: %d\n", queue[rear]);
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (front to rear): ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

void main() {
    int choice, val;
    clrscr();
    do {
        printf("\n1.INSERT 2.DELETE 3.DISPLAY 4.FRONT 5.REAR 6.EXIT\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                delete_item();
                break;
            case 3:
                display();
                break;
            case 4:
                show_front();
                break;
            case 5:
                show_rear();
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
