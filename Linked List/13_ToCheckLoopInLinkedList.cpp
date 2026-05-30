// To check loop in linked list ...

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

// To check loops in linked list ..
int isLoop(struct Node *first) {
    struct Node *p, *q;
    p = q = first;

    do {
        p = p->next;
        q = q->next;
        q = q ? q->next : NULL;
    } while(p && q && p != q);

    if(p == q) return 1;
    else return 0;
}


int main() {

    // To form loop in linked list ..
    struct Node *t1, *t2;
    int a[] = {10,20,30,40,50};
    create(a,5);
    display(first);
    cout << "\n";

    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;

    int loop =  isLoop(first);
    if(loop) cout <<"Loop is founded";
    else cout << "There is no loop";
    
    return 0;

}