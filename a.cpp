#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void func() {
    
    int t;
    cin >> t;
    while (t--)
    { int n;
    cin >> n;
    queue<int> q;
     for(int i= 0; i <n; i++){
        q.push(i);
     }  
    vector<int> numbers(n); 

    
  for(int k =1;k <= n; k++){
      
       
           
            for(int j=0; j <k; j++) {
                q.push(q.front());
                q.pop();
                
            }
             int pos = q.front();

            q.pop();
            numbers[pos] = k;

        }

     for (int i = 0; i < n; i++)
    {
        cout << numbers[i] << " ";
    }
     cout << "\n";
    }
  
}
int main() {
    func();
    return 0;
}