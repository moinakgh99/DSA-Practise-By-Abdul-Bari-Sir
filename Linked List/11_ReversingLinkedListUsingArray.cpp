// Reversing linked list by elements by using arrays ...

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

// Reversing linked list by elements by using arrays
void reverseLL(struct Node *p) {
    int n = 0;
    struct Node *q = first;
    while(q != NULL) {  // Traversing to count the number of nodes
        n++;
        q = q->next;
    }
    int arr[n];
    int i = 0;

    while(p != NULL) {
        arr[i] = p->data;
        p = p->next;
        i++;
    }
    p = first;
    i--;
    while(p != NULL) {
        p->data = arr[i--];
        p = p->next;
    }
}


int main() {

    int a[] = {10,20,30,40,50};
    create(a,5);

    reverseLL(first);
    display(first);
    
    return 0;

}