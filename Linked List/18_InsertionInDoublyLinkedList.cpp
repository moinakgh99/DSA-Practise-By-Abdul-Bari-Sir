//  Insertion in Doubly linked list ..

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

void insertion(struct Node *p, int pos, int x) {
    struct Node *t;

    int n = 0;
    while(p != NULL) {
        n++;
        p = p->next;
    }
    if(pos < 0 && pos > n) return;

    p = first;

    if(pos == 0) {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else {
        p = first;
        for(int i = 0; i < pos-1; i++) {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->next = p->next;
        t->prev = p;
        if(p->next) p->next->prev = t;
        p->next = t;
    }
}

int main() {
    int arr[] = {10,20,30,40,50};
    create(arr, 5);

    insertion(first,0,90);
    display(first);

    return 0;
}