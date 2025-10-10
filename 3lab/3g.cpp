#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool can_deliver(int child[], int flightneed, int island, int capacity) {
    int sum = 0;
    int flight;
    for(int i = 0; i < island; i++) {
        flightneed = ceil(double(child[i])/double(capacity));
        sum += flightneed;
    }
    return sum <= flight;
}


int main() {
    int island, flight;
    cin >> island >> flight;
    int child[island];

    for(int i = 0; i < island; i++) {
        cin >> child[i];
    }

    int max = child[0];
    for(int i = 0; i < island; i++) {
        if(max < child[i]) {
            max = child[i];
        }
    }

    int l = 1, hi = max;
    int result;
    while(l <= hi) {
        int mid = l + (hi - l) / 2;
        if(can_deliver(child, flight, island, mid)) {
            result = mid;
            hi = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;
}