#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> Boris;
    queue<int> Nursik;

    for(int i = 0;  i < 5; i++) {
        int x;cin >> x;
        Boris.push(x);
    }
    for(int j= 0; j <5; j++) {
      int y;  cin >> y;
        Nursik.push(y);
    }
    int count = 0;
    while (!Boris.empty() && !Nursik.empty())
    {
       if((Boris.front() == 0 && Nursik.front() == 9) || (Boris.front() > Nursik.front()) && !(Boris.front() == 9 && Nursik.front() == 0)){
       
        Boris.push(Boris.front());
        Boris.push(Nursik.front());
         Boris.pop(); Nursik.pop();

       }
       else {
         
       
        Nursik.push(Boris.front());
        Nursik.push(Nursik.front());
        Boris.pop(); Nursik.pop();

        
       }
       count ++;
    }
    if (Boris.empty()) {
        cout << "Nursik" << " " << count;
    }
    else {
        cout << "Boris" << " " << count;
    }
    

}