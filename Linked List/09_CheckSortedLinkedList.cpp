// To check if a linked list is sorted or not ??

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

// To check if the linked lsit is sorted or not ?
int isSorted(struct Node *p, int a[], int n) {
    p = first;
    int x = INT_MIN;
    while(p != NULL) {
        if(p->data < x) return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}


int main() {

    int a[] = {1,5,6,8,9,15,44};
    create(a,7);

    int sort = isSorted(first,a,7);

    if(sort) cout << "It is sorted";
    else cout << "It is not sorted";

    return 0;

}