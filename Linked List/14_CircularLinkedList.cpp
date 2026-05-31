// Circular linked list ..

#include<iostream>
#include<climits>
using namespace std;

struct Node {
    int data;
    struct Node *next;
}*head;

// To create a linked list ...
void create(int arr[], int n) {
    struct Node *t, *last;
    head = new Node;
    head->data = arr[0];
    head->next = head;  // Circular linked list;
    last = head;

    for(int i = 1; i < n; i++) {
        t = new Node;
        t->data = arr[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

// Iterative display
void display(struct Node *p) {
    p = head;
    do {
        cout << " " << p->data;
        p = p->next;
    } while (p != head);
}

// Recursive display 
void recursiveDisplay(struct Node *h) {
    static int flag = 0;
    if(h != head || flag == 0) {
        flag = 1;
        cout << " " << h->data;
        recursiveDisplay(h->next);
    }
    flag = 0;
}

int main() {
    int arr[] = {1,2,3,4,5};
    create(arr,5);
    recursiveDisplay(head);

    return 0;
}