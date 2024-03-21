#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* next;
    Node* tail;
};

struct Queue {
    Node* HEAD = nullptr;
    Node* TAIL = nullptr;
    Node* NIL = nullptr;
    size_t  size = 0;
};

Queue* create_empty_queue();
void push(Queue *, int);
void pop(Queue *);
bool empty(Queue *);
Node* first(Queue *);
size_t size(Queue *);

Queue* create_empty_queue() {
    Queue *queue = new Queue;
    queue->HEAD = new Node;
    queue->TAIL = queue->HEAD;
    queue->NIL = queue->HEAD;
    return queue;
}

void push(Queue *q, int key) {
    Node *a = new Node;
    a->key = key;
    a->next = q->NIL;
    if (empty(q)) {
        q->HEAD = a;
        q->TAIL = a;
    } else {
        q->HEAD->next = q->HEAD;
        q->HEAD = a;
    }
    q->size ++;
}

void pop(Queue *q) {
    if (q->HEAD == nullptr) return;
    Node *a = q->HEAD->next;
    q->HEAD = a;
    delete q->HEAD->tail;
    q->size --;
}

Node* first(Queue *q) {
    return q->HEAD;
}

size_t size(Queue *q) {
    return q->size;
}

bool empty(Queue *q) {
    if (q->size != 0) return true;
    return false;
}

int main(){
    return 0;
}