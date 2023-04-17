
#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};
typedef struct node Node;

Node *head;

void push(int value){
    Node *temp = malloc(sizeof(Node));
    if (head == NULL){
        temp->val = value;
        temp->next = NULL;
        head = temp;
    }
    else{
        temp->val = value;
        temp->next = head;
        head = temp;
    }
}

int pop(){
    if (head == NULL) return (-1);// u can make a function to check if empty
    Node *tmp = head;

    int poped = tmp->val;
    head = head->next;
    return poped;
}


int main(){
    for (int i=0; i < 10;i++)push(i);
    //push(5);
    //push(3);
    int poped= pop();

    while (poped != -1){

            printf("%d-", poped);
            poped = pop();

    }
    return 0;
}
























/**
// Initializing the stack using an array
int my_stack[STACK_LENGTH];
// Initializing the top of the stack to be -1
int top = TOP;

// Push element to the top of the stack
bool push(int value){
    if (top >= STACK_LENGTH-1){
        return false;
    }

    top++;
    my_stack[top] = value;
    return true;
}
// Remove and return the top most element of the stack
int pop(){

    if (top == EMPTY) return (-1);// -1 is just an example
    int poped = my_stack[top];
    top--;
    return poped;
}
int main(){
    push(1);
    push(3);
    push(5);
    int f = pop();
    while(f != 99){
            printf("%d", f);
            f = pop();
    }
    return 0;
}













**/
