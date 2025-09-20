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
    int m;
   
    cin >> m;
    
   if(isPrime(m)) {
    cout << "YES";
   }
   else {
    cout <<"NO";
   }
    return 0;
}