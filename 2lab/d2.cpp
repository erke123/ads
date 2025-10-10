#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

int main() {
    int n, x, mx = 0;
    map<int, int> mp;
    cin >> n;

    Node* head = nullptr, *tail = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> x;
        mp[x]++;
        mx = max(mx, mp[x]);
        Node* node = new Node(x);
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    Node* cur = head;
    set<int> st;

    while (cur != nullptr) {
        if (mp[cur->val] == mx) {
            st.insert(cur->val);
        }
        cur = cur->next;
    }

    for (auto it = st.rbegin(); it != st.rend(); it++) {
        cout << *it << " ";
    }

    return 0;
}
