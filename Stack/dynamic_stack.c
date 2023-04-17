#include <ctype.h>
#include <stdio.h>

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

