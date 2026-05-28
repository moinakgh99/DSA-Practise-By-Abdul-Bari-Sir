// Calculate the sum of elements of nodes in a linked list ( Iterative + recursive function ).

#include<iostream>
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

// Iterative function
int add(struct Node *p) {
    int s = 0;
    while(p != NULL) {
        s += p->data;
        p = p->next;
    }
    cout<<s;
}


// Recursive Function
int recursiveAdd(struct Node *p) {
    if(p == 0) return 0;
    else return recursiveAdd(p->next) + p->data;
}

int main() {
    int a[] = {1,5,6,8,9,15,44};

    create(a,7);
    // add(first);
    cout << recursiveAdd(first);

    return 0;

}