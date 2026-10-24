#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginning(struct Node **headRef, int value)
{
    struct Node *newNode = createNode(value);

    newNode->next = *headRef;
    *headRef = newNode;

    printf("Inserted %d at the beginning.\n", value);
}

void insertAtEnd(struct Node **headRef, int value)
{
    struct Node *newNode = createNode(value);
    struct Node *temp;

    if (*headRef == NULL)
    {
        *headRef = newNode;
        printf("Inserted %d at the end.\n", value);
        return;
    }

    temp = *headRef;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    printf("Inserted %d at the end.\n", value);
}

void insertAtPosition(struct Node **headRef, int value,
                      int position)
{
    struct Node *temp;
    struct Node *newNode;
    int i;

    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1)
    {
        insertAtBeginning(headRef, value);
        return;
    }

    temp = *headRef;

    for (i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position! Position is out of bounds.\n");
        return;
    }

    newNode = createNode(value);

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d at position %d.\n", value, position);
}

void displayList(struct Node *head)
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void freeList(struct Node *head)
{
    struct Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;

    clrscr();

    printf("INSERTION IN SINGLY LINKED LIST\n\n");

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    displayList(head);

    printf("\n");

    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    displayList(head);

    printf("\n");

    insertAtPosition(&head, 15, 2);
    displayList(head);

    printf("\n");

    insertAtPosition(&head, 5, 1);
    displayList(head);

    printf("\n");

    insertAtPosition(&head, 100, 10);
    displayList(head);

    freeList(head);

    getch();
    return 0;
}
