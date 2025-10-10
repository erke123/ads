#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[1000000];
    long long pref[1000000]; 

    for (int i = 1; i <= n; i++) 
        cin >> arr[i];

    sort(arr + 1, arr + 1 + n);

    pref[0] = 0;
    for (int i = 1; i <= n; i++) 
        pref[i] = pref[i - 1] + arr[i];

    int p;
    cin >> p;

    while (p--) {
        int x;
        cin >> x;

        int l = 0, r = n + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (arr[mid] > x) r = mid;
            else l = mid;
        }

        cout << l << " " << pref[l] << "\n";
    }

    return 0;
}