
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next, *prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
    public:
    Node *tail, *front;
    
    LinkedList() {
        tail = NULL;
        front = NULL;
    }

    void push_back(int data) {
        Node *node = new Node(data);
        if (tail == NULL) {
            tail = node;
            front = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }


    void print() {
        Node *node = front;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    
 void push_front(int data) {
        Node *node = new Node(data);
        if (front == NULL) {
            tail = node;
            front = node;
        } else {
            front->prev = node;
            node->next = front;
            front = node;
        }
    }
    void insert_node(Node *node1, int data ,int pos) {
        Node *node = new Node(data);
        
        if (node1 == tail) 
            push_back(data);
        else {
            Node *node2 = node1->next;
            node1->next = node;
            node->prev = node1;
            node->next = node2;
            node2->prev = node;
        }
    }
};

int main() {
    int n;
    cin >>n;
    LinkedList *ll = new LinkedList();
    for(int i =0; i < n; i++) {
        int x;
        cin >>x;
        ll->push_back(x);
    }
    int num;
    int pos;
    cin >> num;
    cin >> pos;
    if (pos == 0) {
        ll->push_front(num);
    }

   else { Node* cur = ll->front;
    for(int i =0; i <pos-1; i++) {
        cur= cur->next;
    }
    ll ->insert_node(cur, num,pos);}
    ll->print();
    cout << " ";
    return 0;
   
}