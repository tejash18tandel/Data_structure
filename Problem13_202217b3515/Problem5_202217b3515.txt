[Yesterday 6:57 PM] Patil, Madhavi
#include <stdio.h>

#include <stdlib.h>
 
struct node {

    int data;

    struct node *right_child;

    struct node *left_child;

};
 
struct node* new_node(int x) {

    struct node *temp = malloc(sizeof(struct node));

    if (temp == NULL) {

        perror("Memory allocation failed");

        exit(EXIT_FAILURE);

    }

    temp->data = x;

    temp->left_child = NULL;

    temp->right_child = NULL;

    return temp;

}
 
struct node* search(struct node *root, int x) {

    if (root == NULL || root->data == x)

        return root;

    if (x < root->data)

        return search(root->left_child, x);

    else

        return search(root->right_child, x);

}
 
struct node* insert(struct node *root, int x) {

    if (root == NULL)

        return new_node(x);

    if (x < root->data)

        root->left_child = insert(root->left_child, x);

    else if (x > root->data)

        root->right_child = insert(root->right_child, x);

    return root;

}
 
struct node* find_minimum(struct node *root) {

    if (root == NULL)

        return NULL;

    if (root->left_child == NULL)

        return root;

    return find_minimum(root->left_child);

}
 
struct node* delete_node(struct node *root, int x) {

    if (root == NULL)

        return root;

    if (x < root->data)

        root->left_child = delete_node(root->left_child, x);

    else if (x > root->data)

        root->right_child = delete_node(root->right_child, x);

    else {

        // Node to be deleted found

        // Case 1: Node has no children (leaf node)

        if (root->left_child == NULL && root->right_child == NULL) {

            free(root);

            return NULL;

        }

        // Case 2: Node has one child

        else if (root->left_child == NULL) {

            struct node *temp = root->right_child;

            free(root);

            return temp;

        }

        else if (root->right_child == NULL) {

            struct node *temp = root->left_child;

            free(root);

            return temp;

        }

        // Case 3: Node has two children

        else {

            struct node *temp = find_minimum(root->right_child);

            root->data = temp->data;

            root->right_child = delete_node(root->right_child, temp->data);

        }

    }

    return root;

}
 
void inorder(struct node *root) {

    if (root != NULL) {

        inorder(root->left_child);

        printf("%d ", root->data);

        inorder(root->right_child);

    }

}
 
void free_tree(struct node *root) {

    if (root != NULL) {

        free_tree(root->left_child);

        free_tree(root->right_child);

        free(root);

    }

}
 
int main() {

    struct node *root = NULL;
 
    // Inserting elements into the BST

    root = insert(root, 20);

    insert(root, 5);

    insert(root, 1);

    insert(root, 15);

    insert(root, 9);

    insert(root, 7);

    insert(root, 12);

    insert(root, 30);

    insert(root, 25);

    insert(root, 40);

    insert(root, 45);

    insert(root, 42);
 
    // Print inorder traversal (sorted order)

    printf("Inorder traversal before deletions:\n");

    inorder(root);

    printf("\n");
 
    // Deleting elements from the BST

    root = delete_node(root, 1);

    root = delete_node(root, 40);

    root = delete_node(root, 45);

    root = delete_node(root, 9);
 
    // Print inorder traversal after deletions

    printf("Inorder traversal after deletions:\n");

    inorder(root);

    printf("\n");
 
    // Freeing allocated memory

    free_tree(root);
 
    return 0;

}

 