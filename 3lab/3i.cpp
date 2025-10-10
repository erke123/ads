#include <iostream>
#include <vector>
using namespace std;

bool binary_search_exact(vector<int>& a, int x) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2; 
        if (a[mid] == x) return true;
        if (a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return false; 
}

int main() {
    int r;
    cin >> r;
    vector<int> a(r) ;
    for (int i = 0; i < r; i++)
    {
       
       cin >> a[i];

    }
    
    int x;
    cin >> x;
    if(binary_search_exact(a,x)  ) {
       
         cout << "Yes\n";
    }
    else {
        
         cout << "No\n";
    }
   return 0;
}