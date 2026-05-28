// Finding maximum element in the linked list..

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


// Iterative function
int max(struct Node *p) {
    int maxi = INT_MIN;
    while(p != NULL) {
        maxi = max(maxi, p->data);
        p = p->next;
    }
    return maxi;
}


// Recursive Function
int recursiveMax(struct Node *p) {
    int maxi = INT_MIN;
    if(p == 0) return INT_MIN;
    int x = recursiveMax(p->next);
    return x > p->data ? x : p->data;
}

int main() {
    int a[] = {1,5,6,8,9,15,44};

    create(a,7);
    //cout << max(first);
    cout << recursiveMax(first);

    return 0;

}