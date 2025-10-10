#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binaryLower(const vector<int>& a, int x) {
    int l = 0, r = (int)a.size();
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] < x) l = mid + 1;
        else r = mid;
    }
    return l;
}

int binaryUpper(const vector<int>& a, int x) {
    int l = 0, r = (int)a.size();
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) l = mid + 1;
        else r = mid;
    }
    return l; 
}
int countInRange(const vector<int>& a, int L, int R) {
    if (L > R) return 0;
    int left = binaryLower(a, L);
    int right = binaryUpper(a, R);
    return right - left;}
int main() {
    int n , q, x;
    cin >> n >> q; 
    
    vector<int> a(n);
    for(int i = 0; i < n ; i++)
        cin >> a[i];
    sort(a.begin(), a.end()) ;  

    

         vector<pair<pair<int,int>, pair<int,int>>> queries(q);
    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        queries[i] = {{l1, r1}, {l2, r2}};
    }

    for (auto &qq : queries) {
        int l1 = qq.first.first;
        int r1 = qq.first.second;
        int l2 = qq.second.first;
        int r2 = qq.second.second;

        int c1 = countInRange(a, l1, r1);
        int c2 = countInRange(a, l2, r2);

       
        int li = max(l1, l2);
        int ri = min(r1, r2);
        int cInt = countInRange(a, li, ri);

        cout << (c1 + c2 - cInt) << "\n";
    }

    return 0;
}