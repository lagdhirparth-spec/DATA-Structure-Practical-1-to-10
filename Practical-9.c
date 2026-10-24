#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node* left;
struct Node* right;
};

struct Node* createNode(int value) {
struct Node* newNode;
newNode = (struct Node*)malloc(sizeof(struct Node));

if (newNode == NULL) {
printf("Memory allocation failed!\n");
exit(1);
}

newNode->data = value;
newNode->left = NULL;
newNode->right = NULL;

return newNode;
}

struct Node* insert(struct Node* root, int value) {
if (root == NULL) {
return createNode(value);
}

if (value < root->data) {
root->left = insert(root->left, value);
}
else if (value > root->data) {
root->right = insert(root->right, value);
}

return root;
}

void inorder(struct Node* root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}

void main() {
struct Node* root = NULL;

clrscr();

root = insert(root, 50);
root = insert(root, 30);
root = insert(root, 70);
root = insert(root, 20);
root = insert(root, 40);
root = insert(root, 60);
root = insert(root, 80);

printf("Inorder traversal of BST:\n");
inorder(root);

getch();
}
