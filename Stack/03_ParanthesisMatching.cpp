#include<bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;
}*top = NULL;

void push(char x) {
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
    char x = -1;
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

int isBalanced(char *exp) {
    for(int i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(') push(exp[i]);
        else if(exp[i] == ')') {
            if(top == NULL) return 0;
            pop();
        }
    }
    return top == NULL ? 1:0;
}

int main() {
    
    char exp[] = "((a+b)*((-d))";
    cout << isBalanced(exp);
    return 0;

}