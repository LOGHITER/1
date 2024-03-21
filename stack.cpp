#include <iostream>

struct Node {
    Node* next = NIL; 
    Node* prev = NIL;
    Node* NIL;
    int key = 0;
};

struct stack {
    Node* top;
    Node* bottom = top;
    int size = 0;
};

stack* create_stack() {
    stack* c = new stack;
    return c;
}

bool empty(stack* stack) {
    if(stack->size == 0) {
        return true;
    }
    else {return false;}
}

void push(stack* stack, int key) {
    if(empty(stack)) {
        Node* c = new Node;
        c->key = key;
        c->next = c->NIL;
        c->prev = c->NIL;
        stack->top = c;
        stack->bottom = c;
    }
    else{
    Node* c = new Node;
    stack->top->prev = c;
    c->next = stack->top;
    c->key = key;
    c->prev = c->NIL;
    stack->top = c;
    }
    stack->size += 1;
}

Node* top(stack* stack) {
    if(empty(stack)) {
        return nullptr;
    }   
    return stack->top;
}



void pop(stack* stack) {
    if(empty(stack)) {
    }
    else{
        Node* c = stack->top->next;
        delete stack->top;
        stack->top = c;
        stack->top->prev = stack->top->NIL;
        stack->size -= 1;
    }
}

int size(stack* stack) {
    return stack->size;
}
