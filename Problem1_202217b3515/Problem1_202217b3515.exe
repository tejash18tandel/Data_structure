#include <stdio.h>
#include <stdlib.h>
 
#define MAX 20
 
void create();
void insert();
void deletion();
void search();
void display();
 
int b[MAX];
int n, i, pos;
 
int main() {
    int ch;
    char g = 'y';
 
    do {
        printf("\nMain Menu");
        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);
 
        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("\nEnter the correct choice.\n");
                break; // Added break to terminate default case
        }
 
        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &g);
    } while (g == 'y' || g == 'Y');
 
    return 0;
}
 
void create() {
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
 
    if (n > MAX || n <= 0) {
        printf("\nInvalid number of elements. Please enter a number between 1 and %d.\n", MAX);
        return;
    }
 
    printf("\nEnter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &b[i]);
    }
}
 
void deletion() {
    if (n == 0) {
        printf("\nList is empty. Nothing to delete.\n");
        return;
    }
 
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);
 
    if (pos < 0 || pos >= n) {
        printf("\nInvalid position.\n");
        return;
    }
 
    for (i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }
    n--;
 
    printf("\nThe list after deletion:\n");
    display();
}
 
void search() {
    if (n == 0) {
        printf("\nList is empty.\n");
        return;
    }
 
    int e, found = 0;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);
 
    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Element %d found at position %d.\n", e, i);
            found = 1;
            break; // Assuming you want to find only the first occurrence
        }
    }
 
    if (!found) {
        printf("Element %d not found in the list.\n", e);
    }
}
 
void insert() {
    if (n == MAX) {
        printf("\nList is full. Cannot insert more elements.\n");
        return;
    }
 
    printf("\nEnter the position to insert: ");
    scanf("%d", &pos);
 
    if (pos < 0 || pos > n) {
        printf("\nInvalid position.\n");
        return;
    }
 
    printf("Enter the element to insert: ");
    scanf("%d", &b[n]); // Inserting at the end is often better for simplicity
    n++;
 
    printf("\nThe list after insertion:\n");
    display();
}
 
void display() {
    if (n == 0) {
        printf("\nList is empty.\n");
        return;
    }
 
    printf("\nThe elements in the list are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}
