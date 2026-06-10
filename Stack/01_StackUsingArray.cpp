#include<bits/stdc++.h>
using namespace std;

struct Stack {
    int size;
    int top;
    int *s;
};

void create(struct Stack *st) {
    cout << "Enter the size : ";
    cin >> st->size;
    st->top = -1;
    st->s = new int[st->size];
}

void display(struct Stack st) {
    for(int i = st.top; i >= 0; i--) {
        cout << " " << st.s[i];
        cout << "\n";
    }
}

void push(struct Stack *st, int x) {
    if(st->top == st->size - 1) cout << "Stack Overflow\n";
    else {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct Stack *st) {
    int x = -1;
    if(st->top == -1) cout << "Stack underflow\n";
    else {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int peep(struct Stack st, int pos) {
    int x = -1;
    if(st.top - pos + 1 < 0) cout << "Invalid Position\n";
    else {
        x = st.s[st.top - pos + 1];
    }
    return x;
}

int stackTop(struct Stack st) {
    if(st.top == -1) return -1;
    else {
        return st.s[st.top];
    }
}

int isEmpty(struct Stack st) {
    if(st.top == -1) return 1;
    else return 0;
}

int isFull(struct Stack st) {
    if(st.top == st.size - 1) return 1;
    else return 0;
}

int main() {

    struct Stack st;
    create(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    
    int peepEle = peep(st, 1);
    cout << "Peek Element is : " << peepEle;
    cout << '\n';
    // int popEle2 = pop(&st);
    // cout << "Deleted Element is : " << popEle2;
    // cout << '\n';
    // int popEle3 = pop(&st);
    // cout << "Deleted Element is : " << popEle3;
    // cout << '\n';

    display(st);
}