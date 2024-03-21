#include <iostream>

struct Node
{
    Node* next = nullptr;
    int key = 0;
};


struct queue
{
    Node* HEAD;
    Node* TAIL;
    Node* NIL;
    size_t size = 0;
};

void push_front(Node* queue, int new_data){
    Node* new_node = new Node;
    new_node->key = new_data;
    new_node->next = queue;
    queue = new_node;
}

void push_back(Node* queue, int new_data){
    Node* new_node = new Node;
    new_node->key = new_data;
    Node* ptr = queue;
    if (ptr == nullptr){
        queue = new_node;
        return;
    }
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
}

void insert_after(Node* queue, int new_data){
    Node* new_node = new Node;
    new_node->key = new_data;
    new_node->next = queue->next;
    queue->next = new_node;
}

void destroy_list(Node* queue){
    if(queue == nullptr) {
        return;
    }
    destroy_list(queue->next);
    delete queue->next;
    queue = nullptr;
}

void print_list(Node* queue){
    if (queue == nullptr){
        std::cout << "\n";
        return;
    } 
    Node* ptr = queue;
  while (ptr->next != nullptr) {
    std::cout << ptr->key << ' ';
    ptr = ptr->next;
  }
  std::cout << ptr->key << "\n";
}

Node* find(Node* queue, int key) {
    Node* ptr = queue;
    while (ptr != nullptr && ptr->key != key)
        ptr = ptr->next;
    return ptr;
}

void remove_key(Node* queue, int key) {
    Node* ptr = queue;
    Node* prev_ptr = queue;
    while (ptr != nullptr && ptr->key != key) {
        prev_ptr = ptr;
        ptr = ptr->next;
    }
    if (ptr != nullptr) {
        Node* next = ptr->next;
        if (prev_ptr != ptr) {
            prev_ptr->next = next;
            queue = prev_ptr;
        } else queue = ptr->next;
        delete ptr;
    }
}