#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool can_deliver(int gold[], int hour , int sumka, int capacity ) {
    int sum = 0;
    int hour_need;
    for(int i= 0; i < sumka; i++) {
        hour_need = ceil(double(gold[i])/ double(capacity));
        sum +=hour_need;
    }
    return sum <= hour;
}
int main() {
    int sumka, hour;
    cin >> sumka >> hour;
    int gold[sumka];
    for(int i =0; i < sumka; i++) {
        cin >> gold[i];
    }
    int max = gold[0];
      for(int i =0; i < sumka; i++) {
        if(max < gold[i]) {
            max = gold[i];
        }
      }
      int l =1; int high = max;
     
      while(l <= high) {
        int mid = l + (high - l)/2;
        if(can_deliver(gold, hour , sumka, mid)) {
          
            high = mid -1;
        }
        else {
            l = mid + 1;
        }
      }
      cout << l << endl;
}