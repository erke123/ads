
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(const string& x) : data(x), next(nullptr) {}
};

Node* a(Node* head, int k, int n) {
    if (!head || n <= 1) return head;
    k %= n;
    if (k == 0) return head;

    
    Node* prev = head;
    for (int i = 1; i < k; ++i) {
        prev = prev->next;
    }

    Node* newHead = prev->next; 
    prev->next = nullptr;     

   
    Node* tail = newHead;
    while (tail->next) tail = tail->next;
    tail->next = head;

    return newHead;
}

int main() {
   
   

    int n, k;
    if (!(cin >> n >> k)) return 0;

    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        Node* node = new Node(word);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    head = a(head, k, n);

    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->data;
        if (cur->next) cout << " ";
        cur = cur->next; 
    }
    cout << "\n";
    return 0;
}

