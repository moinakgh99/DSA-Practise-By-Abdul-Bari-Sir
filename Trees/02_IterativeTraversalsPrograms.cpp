#include<bits/stdc++.h>
using namespace std;

struct Stack {
    int size;
    int top;
    struct Node **s;
};

void stackCreate(struct Stack *st, int size) {
    st->size = size;
    st->top = -1;
    st->s = new Node*[st->size];
}

void push(struct Stack *st, struct Node *x) {
    if(st->top == st->size - 1) cout << "Stack Overflow\n";
    else {
        st->top++;
        st->s[st->top] = x;
    }
}

struct Node *pop(struct Stack *st) {
    struct Node *x = NULL;
    if(st->top == -1) cout << "Stack underflow\n";
    else {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int isEmpty(struct Stack st) {
    if(st.top == -1) return 1;
    else return 0;
}

int isFull(struct Stack st) {
    if(st.top == st.size - 1) return 1;
    else return 0;
}

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue {
    int size;
    int front;
    int rear;
    Node **Q;
};

void create(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = 0;
    q->Q = new Node*[q->size];
}

void enqueue(struct Queue *q, Node *x) {
    if( (q->rear+1) % q->size == q->front) cout << "Queue is full";
    else {
        q->rear = (q->rear+1) % q->size;
        q->Q[q->rear] = x;
    }
}

Node *dequeue(struct Queue *q) {
    Node *x = NULL;
    if(q->front == q->rear) cout << "Queue is empty";
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q) {
    return q.rear == q.front;
}

struct Node *root = NULL;

void treeCreate() {
    struct Node *p , *t;
    int x;
    struct Queue q;
    create(&q, 100);

    cout << "Enter the value of Root : ";
    cin >> x;

    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while(!isEmpty(q)) {
        p = dequeue(&q);

        cout << "Enter the left child : ";
        cin>>x;

        if(x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t); 
        }

        cout << "Enter the right child : ";
        cin>>x;

        if(x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t); 
        }
    }
}

void preorder(struct Node *p) {
    if(p) {
        cout << " " << p->data;
        preorder(p->lchild);
        preorder(p->rchild);
    } 
}

void inorder(struct Node *p) {
    if(p) {
        inorder(p->lchild);
        cout << " " << p->data;
        inorder(p->rchild);
    } 
}
void postorder(struct Node *p) {
    if(p) {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << " " << p->data;
    } 
}