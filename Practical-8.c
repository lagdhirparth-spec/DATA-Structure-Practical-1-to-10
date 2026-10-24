#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
int info;
struct node *prev, *next;
};

struct node *start = NULL;

void traverse() {
struct node *temp;
if (start == NULL) {
printf("\nList is empty\n");
return;
}
temp = start;
printf("\nDoubly Linked List:\n");
while (temp != NULL) {
printf("%d <-> ", temp->info);
temp = temp->next;
}
printf("NULL\n");
}

void insertAtFront() {
int data;
struct node *temp;
temp = (struct node*)malloc(sizeof(struct node));
if (temp == NULL) {
printf("Memory allocation failed\n");
return;
}
printf("\nEnter number to be inserted: ");
scanf("%d", &data);
temp->info = data;
temp->prev = NULL;
temp->next = start;
if (start != NULL)
start->prev = temp;
start = temp;
}

void insertAtEnd() {
int data;
struct node *temp, *trav;
temp = (struct node*)malloc(sizeof(struct node));
if (temp == NULL) {
printf("Memory allocation failed\n");
return;
}
printf("\nEnter number to be inserted: ");
scanf("%d", &data);
temp->info = data;
temp->next = NULL;
temp->prev = NULL;
if (start == NULL) {
start = temp;
return;
}
trav = start;
while (trav->next != NULL)
trav = trav->next;
trav->next = temp;
temp->prev = trav;
}

void insertAtPosition() {
int data, pos, i;
struct node *temp, *newnode;
printf("\nEnter position: ");
scanf("%d", &pos);
if (pos < 1) {
printf("Invalid position\n");
return;
}
if (pos == 1) {
insertAtFront();
return;
}
temp = start;
for (i = 1; i < pos - 1 && temp != NULL; i++)
temp = temp->next;
if (temp == NULL) {
printf("Position out of bounds\n");
return;
}
newnode = (struct node*)malloc(sizeof(struct node));
if (newnode == NULL) {
printf("Memory allocation failed\n");
return;
}
printf("\nEnter number to be inserted: ");
scanf("%d", &data);
newnode->info = data;
newnode->next = temp->next;
newnode->prev = temp;
if (temp->next != NULL)
temp->next->prev = newnode;
temp->next = newnode;
}

void deleteFirst() {
struct node *temp;
if (start == NULL) {
printf("\nList is empty\n");
return;
}
temp = start;
start = start->next;
if (start != NULL)
start->prev = NULL;
free(temp);
printf("\nFirst node deleted\n");
}

void deleteEnd() {
struct node *temp;
if (start == NULL) {
printf("\nList is empty\n");
return;
}
temp = start;
if (temp->next == NULL) {
start = NULL;
free(temp);
printf("\nLast node deleted\n");
return;
}
while (temp->next != NULL)
temp = temp->next;
temp->prev->next = NULL;
free(temp);
printf("\nLast node deleted\n");
}

void deletePosition() {
int pos, i;
struct node *temp;
printf("\nEnter position: ");
scanf("%d", &pos);
if (pos < 1 || start == NULL) {
printf("\nInvalid position or list is empty\n");
return;
}
if (pos == 1) {
deleteFirst();
return;
}
temp = start;
for (i = 1; i < pos && temp != NULL; i++)
temp = temp->next;
if (temp == NULL) {
printf("\nPosition out of bounds\n");
return;
}
temp->prev->next = temp->next;
if (temp->next != NULL)
temp->next->prev = temp->prev;
free(temp);
printf("\nNode deleted from position %d\n", pos);
}

void main() {
int choice;
clrscr();
while (1) {
printf("\n\n--- DOUBLY LINKED LIST ---\n");
printf("1. Display List\n");
printf("2. Insert at Beginning\n");
printf("3. Insert at End\n");
printf("4. Insert at Position\n");
printf("5. Delete from Beginning\n");
printf("6. Delete from End\n");
printf("7. Delete from Position\n");
printf("8. Exit\n");
printf("\nEnter Choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
traverse();
break;
case 2:
insertAtFront();
break;
case 3:
insertAtEnd();
break;
case 4:
insertAtPosition();
break;
case 5:
deleteFirst();
break;
case 6:
deleteEnd();
break;
case 7:
deletePosition();
break;
case 8:
while (start != NULL)
deleteFirst();
getch();
return;
default:
printf("\nIncorrect Choice. Try Again\n");
}
}
}
