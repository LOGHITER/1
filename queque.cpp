#include <iostream>

struct Node
{
    Node* next = nullptr;
    Node* tail = nullptr;
    int key = 0;
};


struct queue
{
    Node* HEAD = nullptr;
    Node* TAIL = nullptr;
    Node* NIL = nullptr;
    size_t size = 0;
};

void push(Node* queue, int new_data){
    Node* new_node = new Node;
    new_node->key = new_data;
    new_node->next = queue;
    queue = new_node;
}

void pop(Node* queue){
    Node* new_node = new Node;
    new_node = queue->next;
    delete queue;
    queue = new_node;
}

void first(Node* queue){
    while(queue->tail != nullptr) queue = queue->tail;
//    return queue->key;
};

size_t size(Node* queue){
    int s = 0;
    while (queue != nullptr){
        s += 1;
        queue = queue->next;
    }
    return s;
}

bool empty(Node* queue){
    if (queue != nullptr) return false;
    return true;
}

int main(){
    Node* HEAD = nullptr;
    push(HEAD, 0);
    push(HEAD, 1);
    push(HEAD, 2);
    std::cout << size(HEAD);
    return 0;
}