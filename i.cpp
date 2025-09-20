#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> S;
    queue<int> K;
    int n;
    cin >> n;
    char s;
    
    for(int i =0; i< n; i++) {
        cin >> s;
        if( s == 'S') {
            S.push(i);
        }
        else {
            K.push(i);
        }

    }
    int pos = n;
    while(!S.empty() 
    && !K.empty()) {
        if(S.front() > K.front()) {
            S.pop(); K.pop();
            K.push(pos);
        }
        else {
            S.pop(); K.pop();
            S.push(pos);
        }
        pos++;

    }
    if(S.empty()) {
        cout << "KATSURAGI";
    }
    else {
        cout << "SAKAYANAGI";
    }

}