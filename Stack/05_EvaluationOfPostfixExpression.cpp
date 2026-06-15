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

int eval(char *postfix) {
    int x1, x2, r;
    for(int i = 0; postfix[i] != '\0'; i++) {
        if(isOperand(postfix[i])) {
            push(postfix[i]- '0');
        }
        else {
            x2 = pop(), x1 = pop();
            switch(postfix[i]) {
                case '+' : r = x1 + x2; push(r); break;
                case '-' : r = x1 - x2; push(r); break;
                case '*' : r = x1 * x2; push(r); break;
                case '/' : r = x1 / x2; push(r); break;
            }
        }
    }
    return pop();
}

int main() {
    
    char postfix[] = "234*+82/-";
    int res = eval(postfix);
    cout << res;
    return 0;

}