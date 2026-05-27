// Display the linked list

#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first;

void create(int a[], int n) {
    int i;
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

int main() {
    int a[] = {1,5,6,8,9,};

    create(a,5);
    display(first);

    return 0;

}