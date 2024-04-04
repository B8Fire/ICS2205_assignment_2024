#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node *newNode;
struct Node *root;

void insert(int value);
void search(int value);
void deleteNode(int value);

int main() {
    insert(30);
    insert(20);
    insert(40);
    insert(10);
    insert(25);
    insert(35);
    insert(45);
    insert(5);
    insert(15);

    search(30);
    deleteNode(30);
    search(35);
    return 0;
}
void insert(int value) {
    struct Node *newNode = (struct Node*) malloc (sizeof(struct Node));
    struct Node *parent, *current;
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;

    if(root == NULL) {
        root = newNode;
    }
    else {
        current = root;
        parent = NULL;
        while((1 + 1) == 2){   //loop will end using break
            parent = current;
            if(value < parent -> data) {
                current = current -> left;
                if (current == NULL) {
                    parent -> left= newNode;
                    break;
                }
            }
            else{
                current = current -> right;
                if(current == NULL) {
                    parent -> right = newNode;
                    break;
                }
            }
        }
    }
}
void search(int value) {
    struct Node *current, *parent;
    if(root == NULL) {
        printf("\nEmpty tree!");
    }
    else if(value == root -> data) {
        printf("\n%d",root -> data);
    }
    else{
        current = root;
        parent = NULL;
        while((1 +1 ) == 2){
            parent = current;
            if(value == parent ->data) {
                printf("\n%d",parent -> data);
                break;
            }
            if(value < parent -> data){
                current = current -> left;
                if(current == NULL){
                    printf("\nValue not found.");
                    break;
                }
            }
            else
            {
                current = current -> right;
                if(current == NULL){
                    printf("\nValue not found.");
                    break;
                }
            }
        }
    }
}
void deleteNode(int value) {
    struct Node *parent = NULL;
    struct Node *current = root;

    // Search for the node to be deleted
    while (current != NULL && current->data != value) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // If the node was not found
    if (current == NULL) {
        printf("\nValue not found. Deletion failed.");
        return;
    }
    // Case 1: Deleting a leaf node
    if (current->left == NULL && current->right == NULL) {
        // If the node to be deleted is the root node
        if (parent == NULL) {
            root = NULL;
        } else {
            if (parent->left == current) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        }
        free(current);
        printf("\n%d deleted!", value);
    }
    // Case 2: Deleting a node with only one child
    else if (current->left == NULL || current->right == NULL) {
        struct Node *child = (current->left != NULL) ? current->left : current->right;
        // If the node to be deleted is the root node
        if (parent == NULL) {
            root = child;
        } else {
            if (parent->left == current) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }
        free(current);
        printf("\n%d deleted!", value);
    }
    // Case 3: Deleting a node with two children
    else {
        struct Node *successor = current->right;
        struct Node *successorParent = current;
        // Find the in-order successor i.e left-most node in the right subtree
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        // Replace the value of the node to be deleted with the value of the in-order successor
        current->data = successor->data;
        // Delete the in-order successor
        free(successor);
        printf("\n%d deleted!", value);
    }
}
