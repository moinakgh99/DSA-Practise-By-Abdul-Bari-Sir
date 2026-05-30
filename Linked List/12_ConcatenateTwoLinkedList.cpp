// Concatenating two Linked list ..

#include<iostream>
#include<climits>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first, *second = NULL, *third = NULL;

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

void create2(int b[], int n) {
    struct Node *t, *last;
    second = new Node;
    second->data = b[0];
    second->next = NULL;
    last = second;

    for(int i = 1; i < n; i++) {
        t = new Node;
        t->data = b[i];
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

// Concatenating two linked list ..
void concatenate(struct Node *p, struct Node *q) {
    third = p;
    while( p->next != NULL ) {
        p = p->next;
    }
    p->next = q;
}



int main() {

    int a[] = {10,20,30,40,50};
    create(a,5);
    cout << "First Linked list : ";
    display(first);
    cout<<"\n";

    int b[] = {60,70,80,90,100};
    create2(b,5);
    cout << "Second Linked list : ";
    display(second);
    cout<<"\n";

    concatenate(first, second);
    cout << "Concatenated List : ";
    display(third);
    
    return 0;

}