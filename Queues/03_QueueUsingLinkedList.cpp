#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node *t = new Node;
    if(t == NULL) cout << "Queue is full";
    else {
        t->data = x;
        t->next = NULL;

        if(front == NULL) front = rear = t;
        else {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue() {
    struct Node *p;
    int x = -1;

    if(front == NULL) cout << "Queue is empty";
    else {
        p = front;
        front = front->next;
        x = p->data;
        delete(p);
    }
    return x;
}

void display() {
    struct Node *p = front;
    while(p) {
        cout << " " << p->data;
        p = p->next;
    }
    cout << "\n";
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);

    display();

    cout << dequeue();
    return 0;
}