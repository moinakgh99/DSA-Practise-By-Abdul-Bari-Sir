// Improving linear search in linked list by Move to front Operation (MOve to Head) ..

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

// Iterative function
struct Node* linearSearch(Node *p , int key) {
    struct Node *q = NULL;
    while(p != NULL) {
        if(key == p->data) {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
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

    temp = linearSearch(first, 15);
    temp = linearSearch(first, 44);
    // temp = recursiveLinearSearch(first, 15);
    if(temp) cout << "Key is found";
    else cout << "Key is not found";

    display(first);
    
    // cout << recursiveMax(first);

    return 0;

}