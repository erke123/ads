#include <iostream>
using namespace std;
bool isPrime(int m){
    for(int i =2; i*i <= m;i++) {
        if(m%i==0) {
            return false;
        }


    }
    if(m<2){
        return false;
    }
    return true;
    
}

int main() {
    int n;
    cin >> n;
    int count =0;
    int c = 1;
    while(count < n) {
        c++;
            if (isPrime(c)) {
            count ++;

            }
        
    }
    cout << c;
}