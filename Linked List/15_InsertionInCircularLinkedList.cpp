// insertion in Circular linked list ..

#include<iostream>
#include<climits>
using namespace std;

struct Node {
    int data;
    struct Node *next;
}*head;

// To create a linked list ...
void create(int arr[], int n) {
    struct Node *t, *last;
    head = new Node;
    head->data = arr[0];
    head->next = head;  // Circular linked list;
    last = head;

    for(int i = 1; i < n; i++) {
        t = new Node;
        t->data = arr[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

// Insertion in circualr linked list ..
void insert(int pos, int x) {
    struct Node *p, *t;
    if(pos == 0) {
        t = new Node;
        t->data = x;
        if(head == NULL) {
            head = t;
            head->next = head;
        }
        else {
            p = head;
            t->next = head;
            while(p->next != head) {
                p = p->next;
            }
            p->next = t;
            head = t;
        }
    }
    else {
        p = head;
        for(int i = 0; i < pos-1; i++) {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->next = p ->next;
        p->next = t;
    }
}

void display(struct Node *p) {
    p = head;
    do {
        cout << " " << p->data;
        p = p->next;
    } while(p != head);
}


int main() {
    int arr[] = {1,2,3,4,5};
    create(arr,5);

    insert(0,45);
    display(head);

    return 0;
}