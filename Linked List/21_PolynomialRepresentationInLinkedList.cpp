// Representing Polynomial in linked list ..

#include<bits/stdc++.h>
#include<climits>

using namespace std;

struct Node {
    int coff;
    int expo;
    struct Node *next;
}*poly = NULL;

void create() {
    struct Node *t, *last = NULL;
    int num;

    cout << "Enter the  Number of terms : ";
    cin >> num;

    cout << "Enter each term with coff and exponents \n";

    for(int i = 0; i < num; i++) {
        t = new Node;
        cin >> t->coff >> t->expo;
        t->next = NULL;

        if(poly == NULL) {
            poly = last = t;
        }
        else {
            last->next = t;
            last = t;
        }
    }
}

void display(struct Node *p) {
    while(p != NULL) {
        cout << p->coff << "x" << p->expo;
        p = p->next;
    }
    cout << "\n";
}

long evaluate(struct Node *p, int x) {
    long sum = 0;
    while(p != NULL) {
        sum += p->coff * pow(x, p->expo);
        p = p->next;
    }
    return sum;
}

int main() {
    create();
    display(poly);
    cout << evaluate(poly, 1);

    return 0;
}