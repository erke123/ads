#include <iostream>
#include <deque>
using namespace std;
int main() {
     deque<int> dq;
    char c;
    
   
    int n;
    while(true) {
        cin >> c;
       
        if(c== '+') {
             cin >> n;
            dq.push_front(n);
           
        }
       else if(c== '-') {
             cin >> n;
            dq.push_back(n);
        }
       else if (c == '*') {
            if(dq.empty()) {
                cout << "error" << endl;
            }
           
            else {
                 int sum;
                 if(dq.size() ==1) {
                    sum = dq.front() + dq.back();
                    dq.pop_front();
                } 
                else {
                    sum = dq.front() + dq.back();
                    dq.pop_front();
                    dq.pop_back();
                }
cout << sum << endl;
            }
        }
        if (c == '!') {
            break;
        }

    }
    return 0;
}