// Insertion in linked list.

/*
    Two cases are there : 1.) Inserting before the first node
                          2.) Inserting after the given position
*/

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

// Insertion Function
void insert(int pos, int x) {
    struct Node *t, *p;
    if(pos == 0) {
        t = new Node;
        t->data = x;
        t->next = first;
        first = t;
    }
    else if(pos > 0) {
        p = first;
        for(int i = 0; i < pos-1 && p; i++) {
            p = p->next;
        }

        if(p) {
            t = new Node;
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}

int main() {

    // int a[] = {1,5,6,8,9,15,44};
    // create(a,7);

    insert(0,99);
    insert(1,90);
    insert(2,80);
    insert(3,78);
    insert(0,114);
    display(first);

    return 0;

}