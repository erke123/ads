#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    string str;
    cin >> str;
    stack<char> st;
    st.push(str[0]);
    for(int i = 1; i < str.size();i++) {
    
        if(!st.empty() && st.top() == str[i]) {
            st.pop();
        }
        else{
            st.push(str[i]);
        }

    }
    if(st.empty()) {
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}