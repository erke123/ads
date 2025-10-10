#include <bits/stdc++.h>
using namespace std;
bool possible(vector<long long> &a, int n, int k, long long limits) {
    int blocks = 1;
    long long cur = 0;
    for(int i = 0; i <n; i++) {
        if(a[i] > limits) {
            return false;
        }
        if(cur + a[i] <= limits) {
            cur += a[i];
        }
        else {
            blocks ++;
            cur = a[i];
            if(blocks > k) {
                return false;
            }
        }

    }
    return blocks <= k;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector <long long> a(n);

    for(int i =0; i <n ; i++) {
        cin >> a[i];
    }
    long long sum=0, mx = 0;
    for(int i =0; i <n ; i++) {
       sum += a[i];
       mx = max(mx, a[i]);
    }
    long long low = mx, high = sum;
    while(low < high) {
        long long mid = low + (high - low) /2;
        if(possible(a,n,k,mid)) {
            high = mid;
        } else {
            low = mid +1;
        }

    }
    cout << low;

}