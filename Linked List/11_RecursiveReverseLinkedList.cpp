// Reversing linked list by Recursion ...

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

// Reversing linked list by Recursion ..
void reverseLL(struct Node *q, struct Node *p) {
    if( p != NULL ) {
        reverseLL(p, p->next);
        p->next = q;
    } else {
        first = q;
    }
}


int main() {

    int a[] = {10,20,30,40,50};
    create(a,5);

    reverseLL(NULL, first);
    display(first);
    
    return 0;

}