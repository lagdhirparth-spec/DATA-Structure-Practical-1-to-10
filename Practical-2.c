#include <stdio.h>

#define MAX 100

void traverse(int arr[], int n) {
    int i;
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insert(int arr[], int n) {
    int pos, val, i;
    if (n >= MAX) {
        printf("Array is full, cannot insert.\n");
        return n;
    }
    printf("Enter position (0 to %d): ", n);
    scanf("%d", &pos);
    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return n;
    }
    printf("Enter the new element: ");
    scanf("%d", &val);
    for (i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = val;
    n++;
    printf("Element inserted successfully.\n");
    return n;
}

int delete_element(int arr[], int n) {
    int pos, i;
    if (n == 0) {
        printf("Array is empty, cannot delete.\n");
        return n;
    }
    printf("Enter position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return n;
    }
    for (i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("Element deleted successfully.\n");
    return n;
}

void search(int arr[], int n) {
    int key, i, found = 0;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at position %d.\n", key, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element not found.\n");
    }
}

int main() {
    int arr[MAX];
    int n = 0, i, choice;

    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);
    if (n < 0 || n > MAX) {
        printf("Invalid size! Size set to 0.\n");
        n = 0;
    }
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n===== ARRAY OPERATIONS =====\n");
        printf("1. Traversal\n");
        printf("2. Insertion\n");
        printf("3. Deletion\n");
        printf("4. Searching\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse(arr, n);
                break;
            case 2:
                n = insert(arr, n);
                traverse(arr, n);
                break;
            case 3:
                n = delete_element(arr, n);
                traverse(arr, n);
                break;
            case 4:
                search(arr, n);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}
