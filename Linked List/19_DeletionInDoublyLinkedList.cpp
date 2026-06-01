// Deletion in Doubly Linked List ...

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

void deletion(struct Node *p, int pos) {
    int n = 0;
    while(p != NULL) {
        n++;
        p = p->next;
    }

    if(pos < 0 || pos > n) return;

    int x;
    if(pos == 0) {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
        if(first) first->prev = NULL;
    }
    else {
        p = first;
        for(int i = 0; i < pos; i++) {
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next) p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
}

int main() {
    int arr[] = {10,20,30,40,50};
    create(arr, 5);

    deletion(first,2);
    display(first);

    return 0;
}