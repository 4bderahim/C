#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node Node;

void print(Node *head){
    Node *temp = head;

    while (temp != NULL){
        printf("%d-", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// push a new node to the head of the linked list and return the new node;
Node *push_to_head(Node *head,Node *new_node){
    new_node->next = head;
    return new_node;
}

Node *find(Node *head, int val){
    Node *temp = head;
    while (temp != NULL){
        if (temp->value == val){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//inser new node
void insert(Node *node_befor, Node *new_node){
    new_node->next = node_befor->next;
    node_befor->next = new_node;
}



Node *delete_node(Node *head,int target_node_value){
                 Node *target_node;
                 Node *temp = head;
                 target_node = find(temp, target_node_value);

                 if (!target_node){
                        return NULL;
                 }
                // delete from the beginning
                 if (head->value == target_node->value){
                        head = head->next;// now the second node is the head
                        return head;
                 }
                 // first we Traverse to second last element
                 while(temp->next->next !=NULL){
                        //Delete from middle
                        if (temp->next->value == target_node->value){
                                temp->next = temp->next->next;
                                return head;
                        }
                        temp=temp->next;
                }
                 // Delete from end
                 temp->next = NULL;
                 return head;
    }

// creat a new node
Node *creat(int val){
    Node *nr = malloc(sizeof(Node));
    nr->value= val;
    nr->next = NULL;
    return nr;
}

int main(){
    Node *head = NULL;
    Node *temp;
    for (int i = 0; i <= 5; i++){
            temp = creat(i);
            head = push_to_head(head, temp);
    }

    // temp = find(head, 4);

    insert(temp, creat(9));
    head = delete_node(head, 0);
    print(head);
    return 0;
}
