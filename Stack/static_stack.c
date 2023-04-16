#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

#define STACK_LENGTH 5
#define TOP (-1)

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
