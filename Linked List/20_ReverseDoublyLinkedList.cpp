// Reversing the Doubly Linked List ...

#include<iostream>
#include<climits>
using namespace std;

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;

void create(int arr[], int n) {
    struct Node *t, *last;
    t = new Node;
    t->data = arr[0];
    t->prev = t->next = NULL;
    first = last = t;

    for(int i = 1; i < n; i++) {
        t = new Node;
        t->data = arr[i];
        t->next = last->next;
        last->next = t;
        t->prev = last;
        last = t;
    }
}

void display(struct Node *p) {
    while(p != NULL) {
        cout << " " << p->data;
        p = p->next;
    }
}

void reversing(struct Node *p) {
    struct Node *temp;
    while(p != NULL) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p != NULL && p->next == NULL) first = p;
    }
}

int main() {
    int arr[] = {10,20,30,40,50};
    create(arr, 5);

    reversing(first);
    display(first);

    return 0;
}