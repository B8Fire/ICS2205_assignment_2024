/*
BONFACE GEKARA MORARA SCT221-0282/2022
SHADRACK KEBASO       SCT221-0205/2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    char data;
    struct Stack *next;
};
struct Stack *top = NULL;
struct Stack *newStack = NULL;

void push(char value);
void pop();
char peek();
void printStack();

void main() {
    char infix[30];
    int i,j;

    printf("Enter an infix expression with the following operators: + , - , * , / and %%. \nInfix expression : ");
    scanf("%s",&infix);
    printf("\n");
    printf("\nPostfix expression : ");
    i = strlen(infix);

    for(j = 0 ; j < i ; j++) {
        if ((infix[j] >= 48 && infix[j] <= 57) || (infix[j] >= 65 && infix[j] <= 90) ||      // comparing character according to ASCII
            (infix[j] >= 97 && infix[j] <= 122) || infix[j] == 43 || infix[j] == 45 || infix[j] == 42 || infix[j] == 47 || infix[j] == 37) {
            switch(infix[j]) {
            case '+' :
            case '-' :
                for(int k = 1 ; k > 0; k++){
                    char p = peek();
                    if (p == 'e') {
                        push(infix[j]);
                        break;
                    } else if (p == '/' || p == '*' || p == '%'|| p == '-' || p == '+') {
                        printf("%c",peek());
                        pop();
                    }
                }
                break;
            case '/' :
            case '*' :
                for(int k = 1 ; k > 0; k++){
                    char p = peek();
                    if (p == 'e' || p == '%'|| p == '-' || p == '+') {
                        push(infix[j]);
                        break;
                    } else if (p == '/' || p == '*') {
                        printf("%c",peek());
                        pop();
                    }
                }
                break;
            case '%' :
                for(int k = 1 ; k > 0; k++){
                    char p = peek();
                    if (p == 'e' || p == '-' || p == '+') {
                        push(infix[j]);
                        break;
                    } else if (p == '/' || p == '*' || p == '%') {
                        printf("%c",peek());
                        pop();
                    }
                }
                break;
            default:
                printf("%c",infix[j]);
            }
        }
        else {
            printf("This is not an infix expression!");
            break;
        }
    }
    printStack();
    printf("\n\n");
}

void push(char value) {
    struct Stack *newStack = (struct Stack*) malloc (sizeof(struct Stack));
    newStack -> data = value;
    newStack -> next = NULL;

    if(top == NULL) {
        top = newStack;
    } else {
        newStack -> next = top;
        top = newStack;
    }
}
char peek() {
    if(top == NULL) {
        return 'e';//for empty stack
    } else {
        return top -> data;
    }
}
void pop() {
    if(top == NULL) {
        //cannot happen in this case
    } else {
        struct Stack *temp = top;
        top = top -> next;
        free(temp);
    }
}
void printStack() {
    while(top != NULL) {
        printf("%c",peek());
        pop();
    }
}
