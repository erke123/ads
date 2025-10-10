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

   
};

int main() {
    int n;
    cin >> n;
   
    LinkedList *ll = new LinkedList();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
       
        if (i % 2 != 0) {
            
            continue;
        }
        ll->push_back(x);
    }

    
    ll->print();
    cout << " ";
   
    

    return 0;
  
}