// Linear search in Linked list ..
//  Binary search is not possible because it is difficult to find the mid value of linked list

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
struct Node* linearSearch(Node *p , int key) {
    while(p != NULL) {
        if(key == p->data) return p;
        p = p->next;
    }
    return NULL;
}


// Recursive Function
struct Node* recursiveLinearSearch(Node *p , int key) {
    if(p == NULL) return NULL;
    if(key == p->data) return p;

    return recursiveLinearSearch(p->next, key);
}

int main() {

    struct Node *temp;
    int a[] = {1,5,6,8,9,15,44};

    create(a,7);

    // temp = linearSearch(first, 56);
    temp = recursiveLinearSearch(first, 15);
    if(temp) cout << "Key is found";
    else cout << "Key is not found";
    
    // cout << recursiveMax(first);

    return 0;

}