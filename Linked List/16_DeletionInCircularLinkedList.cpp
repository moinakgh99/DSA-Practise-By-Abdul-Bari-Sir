// Deletion in Circular linked list ..

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

// Deletion in circular linked list ..
int deletion(struct Node *p, int pos) {
    int n = 0;
    while(p->next != head) {
        n++;
        p = p->next;
    }

    if(pos < 0 || pos > n) return -1;
    int x;
    if(pos == 0) {
        p = head;
        while(p->next != head) p = p->next;
        x = head->data;

        if(head == p) {
            delete head;
            head = NULL;
        }
        else {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else {
        struct Node *q;
        p = head;
        for(int i = 0; i < pos-1; i++) {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

void display(struct Node *p) {
    p = head;
    do {
        cout << " " << p->data;
        p = p->next;
    } while(p != head);
}


int main() {
    int arr[] = {1,2,15,4,5};
    create(arr,5);

    int deleteNode = deletion(head,4);
    cout << "Deleted Node is : " << deleteNode;
    cout<<"\n";

    cout << "After deletion :";
    display(head);

    return 0;
}