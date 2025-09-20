#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void func() {
    int t;
    cin >> t;
    vector<int> vec(t);
    for (int i = 0; i < t; i++) {
        cin >> vec[i];   
    }

    stack<int> st;
    vector<int> age(t);  

    for (int i = 0; i < t; i++) {
        while (!st.empty() && st.top() >vec[i]) {
            st.pop();
        }

     if (st.empty()) {
            age[i] = -1; 
        } else {
            age[i] = st.top(); 
        }

    st.push(vec[i]); 
    }

    for (int i = 0; i < t; i++) {
        cout << age[i] << " ";
    }
    cout << endl;
}

int main() {
    func();
    return 0;
}
