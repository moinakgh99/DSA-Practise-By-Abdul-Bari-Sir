// Deletion in linked list ..

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

// Deletion Function
int deletion(struct Node *p, int pos) {

    int x;

    // if it is a First node.
    if(pos == 0) {  
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    // If it is a node at given position
    else {
        p = first;
        struct Node *q = NULL;
        for(int i = 0; i < pos - 1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }

    return x;
}

int main() {

    int a[] = {1,5,6,8,9,15,44};
    create(a,7);

    deletion(first, 0);
    display(first);

    return 0;

}