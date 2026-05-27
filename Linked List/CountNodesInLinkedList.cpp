// Counting the number of nodes in the linked list ( Iterative + recursive function ) ...

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

/*
// Iterative function
int count(struct Node *p) {
    int c = 0;
    while(p != NULL) {
        c++;
        p = p->next;
    }
    cout<<c;
}
*/

// Recursive Function
int recursiveCount(struct Node *p) {
    if(p == 0) return 0;
    else return recursiveCount(p->next) + 1;
}

int main() {
    int a[] = {1,5,6,8,9,15,44};

    create(a,7);
    // count(first);
    cout << recursiveCount(first);

    return 0;

}