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

char pop() {
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

int pre(char x) {
    if(x == '+' || x == '-') return 1;
    else if(x == '*' || x == '/') return 2;
    else return 0;
}

int isOperand(char x) {
    if(x == '+' || x == '-' || x == '*' || x == '/') return 0;
    else return 1;
}

char *conversion(char *infix) {
    char *postfix = new char[strlen(infix) + 2];
    int i = 0, j = 0;
    while(infix[i] != '\0') {
        if(isOperand(infix[i])) postfix[j++] = infix[i++];
        else {
            if(pre(infix[i]) > pre(top->data)) {
                push(infix[i++]);
            }
            else {
                postfix[j++] = pop();
            }
        }
    }
    while(top != NULL) postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}

int main() {
    
    char infix[] = "a+b*c-d/e";
    push('#');
    char *postfix = conversion(infix);
    cout << postfix;
    
    return 0;

}