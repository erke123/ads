#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
 string str;
 string strr;
    cin >> str;
    cin >> strr;
    stack<char> st;
    st.push(str[0]);
    for(int i = 1; i < str.size();i++) {
       
        
        if(str[i] == '#') {
            st.pop();
        }
        else{
            st.push(str[i]);
        }
        

    }
     stack<char> sr;
    sr.push(strr[0]);
    for(int i = 1; i < strr.size();i++) {
       
        
        if(strr[i] == '#') {
            sr.pop();
        }
        else{
            sr.push(strr[i]);
        }

    }
    if(st == sr) {
        
        cout << "YES";
    }
    else {
        cout << "NO";
    }

   }

