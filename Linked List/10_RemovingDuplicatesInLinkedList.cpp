// Removing duplicates in linked list ...

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

// Removing duplicates in linked list
void removeDuplicates(struct Node *p) {
    p = first;
    struct Node *q = first->next;

    while(q != NULL) {
        if(p->data != q->data) {
            p = q;
            q = q->next;
        }
        else {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}


int main() {

    int a[] = {10,10,20,20,20,30,40,50,50,50};
    create(a,10);

    removeDuplicates(first);
    display(first);
    
    return 0;

}