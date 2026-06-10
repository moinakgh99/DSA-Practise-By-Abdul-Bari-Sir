#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
}*top = NULL;

void push(int x) {
    struct Node *t;
    t = new Node;

    if(t == NULL) cout << "Stack overflow\n";
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop() {
    int x = -1;
    struct Node *p;
    if(top == NULL) cout << "Stack underflow\n";
    else {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}

void display() {
    struct Node*p = top;
    while(p != NULL) {
        cout << " " << p->data;
        cout << "\n";
        p = p->next;
    }
}

int main() {
    
    push(10);
    push(20);
    push(30);
    cout << "\n";

    display();

    int popEle = pop();
    cout << "Deleted Element is : " << popEle;
    cout << "\n";

    display();

    return 0;

}