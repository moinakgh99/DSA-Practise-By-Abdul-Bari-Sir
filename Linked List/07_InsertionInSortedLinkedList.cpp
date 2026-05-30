// Insertion in sorted linked list..

#include<iostream>
#include<climits>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first;

void create(int a[], int n) {
    struct Node *t, *last;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++) {
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p) {
    while(p != NULL) {
        cout << " " << p->data ;
        p = p->next;
    }
}

// Insertion Function in sorted linked list
void sortedInsert(struct Node *p, int x) {
    struct Node *t, *q = NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if(p == NULL) first = t;   // Because we created the node first before checking
    else {
        while(p && p->data < x) {
            q = p;
            p = p->next;
        }
        if(p == first) {
            t->next = first;
            first = t;
        }
        else {
            t->next = q->next;
            q->next = t;
        }
    }
}


int main() {

    // int a[] = {1,5,6,8,9,15,44};
    // create(a,7);
    sortedInsert(first, 12);
    sortedInsert(first, 55);
    sortedInsert(first, 10);
    display(first);

    return 0;

}