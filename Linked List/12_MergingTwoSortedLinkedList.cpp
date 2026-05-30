// Merging two Linked list ..
// Merging two sorted linked list into a single sorted linked list ..

#include<iostream>
#include<climits>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first, *second = NULL, *third = NULL;

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

void create2(int b[], int n) {
    struct Node *t, *last;
    second = new Node;
    second->data = b[0];
    second->next = NULL;
    last = second;

    for(int i = 1; i < n; i++) {
        t = new Node;
        t->data = b[i];
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


/*
    We will use two Pointer : Third and last pointers.
    Third : points the first node of the merged linked list
    last : points the last node of the merged linked list
*/

// Merging two Linked list ..
void mergingSortedList(struct Node *p, struct Node *q) {
    struct Node *last;

    /* 
        STEP 1 : Check first node which is smaller
        Move the both third and last pointer to the smallest node.
        make last->next = NULL
    */
    if(p->data < q->data) {
        third = last = p;
        p = p->next;
        last->next = NULL;   
    }
    else {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }

    /*
        STEP 2 : Repeatative steps..
    */
   while( p != NULL && q != NULL) {
        if( p->data < q-> data ) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else {
           last->next = q;
            last = q;
            q = q->next;
            last->next = NULL; 
        }
   }

   /*
        STEP 3 : If any list remains ...
   */
   
   if( p != NULL) last->next = p;
   else last->next = q;
}



int main() {

    int a[] = {2,8,10,15};
    create(a,4);
    cout << "First Linked list : ";
    display(first);
    cout<<"\n";

    int b[] = {4,7,12,14};
    create2(b,4);
    cout << "Second Linked list : ";
    display(second);
    cout<<"\n";

    mergingSortedList(first, second);
    cout << "Concatenated List : ";
    display(third);
    
    return 0;

}