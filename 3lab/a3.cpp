#include <bits/stdc++.h>
using namespace std;
int binary_search(vector<int>& arr,int  x, bool increasing = true ) {
    int l =0;
    int r = arr.size();
    while(l <= r) {
        int mid = (l + r) /2;
        if(arr[mid] == x) {
            return mid;
        }
        if(increasing) {
            if (arr[mid] < x) {
                l = mid +1;
            }
            else {
                r = mid -1;
            }

        }
        else {
            if (arr[mid] > x) {
                l = mid + 1;
            }
            else {
                r = mid -1;
            }
        }

    }
    return -1;

}
int main() {
   

    int t;
    cin >> t;
    vector<int> queries(t);
    for (int i = 0; i < t; i++) cin >> queries[i];

    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

  
    for (int x : queries) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            bool increasing = matrix[i][0] < matrix[i][m - 1];
            int j = binary_search(matrix[i], x, increasing);
            if (j != -1) {
                cout << i << " " << j << "\n";
                found = true;
                break;
            }
        }
        if (!found) cout << -1 << "\n";
    }

    return 0;
}