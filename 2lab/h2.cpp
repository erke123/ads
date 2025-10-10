#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
};

class LinkedList {
public:

    Node* insert(Node* head, Node* node, int p){
        if (p == 0) {
            node->next = head;
            return node;
        }
        Node* cur = head;
        for (int i = 0; i < p-1; ++i)
            cur = cur->next;
        node->next = cur->next;
        cur->next = node;
        return head;
    }

    Node* remove(Node* head, int p){
        if (p == 0) {
            Node* tmp = head->next;
            delete head;
            return tmp;
        }
        Node* cur = head;
        for (int i = 0; i < p-1; ++i)
            cur = cur->next;
        Node* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        return head;
    }

    Node* replace(Node* head, int p1, int p2){
        if (p1 == p2) return head;
        Node* prev1 = nullptr;
        Node* cur1 = head;
        for (int i = 0; i < p1; ++i) {
            prev1 = cur1;
            cur1 = cur1->next;
        }
        if (prev1) prev1->next = cur1->next;
        else head = cur1->next;

        Node* cur2 = head;
        Node* prev2 = nullptr;
        for (int i = 0; i < p2; ++i) {
            prev2 = cur2;
            cur2 = cur2->next;
        }
        if (prev2) {
            cur1->next = prev2->next;
            prev2->next = cur1;
        } else {
            cur1->next = head;
            head = cur1;
        }
        return head;
    }

    Node* reverse(Node* head){
        Node* prev = nullptr;
        Node* cur = head;
        while(cur) {
            Node* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }

    void print(Node* head){
        if (!head) { cout << -1 << endl; return; }
        Node* cur = head;
        while(cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    Node* cyclic_left(Node* head, int x){
        if (!head || !head->next) return head;
        Node* cur = head;
        int len = 1;
        while(cur->next) { cur = cur->next; len++; }
        cur->next = head; 
        x %= len;
        Node* tail = head;
        for(int i=0; i<x-1; i++) tail = tail->next;
        head = tail->next;
        tail->next = nullptr;
        return head;
    }

    Node* cyclic_right(Node* head, int x){
        if (!head || !head->next) return head;
        Node* cur = head;
        int len = 1;
        while(cur->next) { cur = cur->next; len++; }
        cur->next = head; 
        x %= len;
        int steps = len - x;
        Node* tail = head;
        for(int i=0; i<steps-1; i++) tail = tail->next;
        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};

int main(){
    LinkedList ll;
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0) break;
        else if(command == 1){
            int x, p; cin >> x >> p;
            head = ll.insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = ll.remove(head, p);
        }else if (command == 3){
            ll.print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = ll.replace(head, p1, p2);
        }else if (command == 5){
            head = ll.reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = ll.cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = ll.cyclic_right(head, x);
        }
    }
    return 0;
}
