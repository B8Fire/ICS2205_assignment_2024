#include<stdlib.h>
#include<stdio.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *frontA = NULL;
struct Node *frontB = NULL;

void insertA(int value);
void insertB(int value);
void getIntersectionNode();

int main(void){

    insertA(10);
    insertA(20);
    insertA(30);
    insertA(40);
    insertA(50);

    insertB(15);
    insertB(25);
    insertB(35);
    insertB(40);

    getIntersectionNode();

    return 0;
}
void insertA(int value){
    struct Node *newNode = (struct Node*) malloc (sizeof(struct Node*));

    newNode->data = value;
    newNode->next=NULL;

    struct Node *current = NULL;

    if(frontA==NULL){
        frontA = newNode;
    }
    else{
        current=frontA;
        while (current->next!=NULL){
            current = current->next;
        }
        current->next=newNode;
    }
}

void insertB(int value){
    struct Node *newNode = (struct Node*) malloc (sizeof(struct Node*));

    newNode->data = value;
    newNode->next=NULL;

    struct Node *current = NULL;

    if(frontB==NULL){
        frontB = newNode;
    }
    else{
        current=frontB;
        while (current->next!=NULL){
            current = current->next;
        }
        current->next=newNode;
    }
}

void getIntersectionNode() {
    struct Node *currentA = frontA;
    struct Node *currentB = frontB;

    while(currentA != NULL) {
        while(currentB != NULL) {
            if(currentB -> data == currentA -> data) {
                printf("\nIntersection node is %d\n",currentB -> data);
                break;
            } else {
                currentB = currentB -> next;
            }
        }
        if(currentA == currentB) {
            break;
        } else {
            currentA = currentA -> next;
        }
    }
    if(currentA == NULL && currentB == NULL) {
        printf("\nNull\n");
    }
}
