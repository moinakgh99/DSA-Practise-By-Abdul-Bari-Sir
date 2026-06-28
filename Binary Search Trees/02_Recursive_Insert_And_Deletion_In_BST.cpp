#include<bits/stdc++.h>
using namespace std;

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;

void insert(int key) {
    struct Node *t = root;
    struct Node *r = NULL, *p;

    if(root == NULL) {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while(t != NULL) {
        r = t;
        if(key < t->data) t = t->lchild;
        else if(key > t->data) t = t->rchild;
        else return;
    }

    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;

    if(p->data < r->data) r->lchild = p;
    else r->rchild = p;
}

void inorder(struct Node *p) {
    if(p) {
        inorder(p->lchild);
        cout << " " << p->data;
        inorder(p->rchild);
    }
}

struct Node *search(int key) {
    struct Node *t = root;
    while(t != NULL) {
        if(key == t->data) return t;
        else if(key < t->data) t = t->lchild;
        else t = t->rchild;
    }
    return NULL;
}

struct Node *recInsert(struct Node *p, int key) {
    if(p == NULL) {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        return p;
    }

    if(key < p->data) p->lchild = recInsert(p->lchild, key);
    else if(key > p->data) p->rchild = recInsert(p->rchild, key);

    return p;
}

int height(struct Node *p) {
    if(p == NULL) return 0;
    int x, y;
    x = height(p->lchild);
    y = height(p->rchild);

    return (x > y) ? x + 1 : y + 1;
}

// left subtree k rightmost child
struct Node *inorderPredecessor(struct Node *p) {  
    while(p && p->rchild != NULL) p = p->rchild;
    return p;
}

// right subtree k leftmost child
struct Node *inorderSuccessor(struct Node *p) {  
    while(p && p->lchild != NULL) p = p->lchild;
    return p;
}

struct Node *deletion(struct Node *p, int key) {

    struct Node *q;

    if(p == NULL) return NULL;
    if(p->lchild == NULL && p->rchild == NULL) {
        if(p == root) root = NULL;
        delete(p);
        return NULL;
    }
    
    if(key < p->data) p->lchild = deletion(p->lchild, key);
    else if(key > p->data) p->rchild = deletion(p->rchild, key);
    else {   // Means both are equal now , now we can delete the node
        if(height(p->lchild) > height(p->rchild)) {
            q = inorderPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = deletion(p->lchild, q->data);
        }
        else {
            q = inorderSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = deletion(p->rchild, q->data);
        }
    }
    return p;
}



int main() {
    struct Node *temp;
    root = recInsert(root,10);
    recInsert(root,5);
    recInsert(root,20);
    recInsert(root,8);
    recInsert(root,30);

    root = deletion(root, 10);
    inorder(root);
    cout << "\n";

    temp = search(2);
    if(temp) cout << "Element is found : " << temp->data;
    else cout << "Element is not found";

    return 0;
}