#include <iostream>
#include <vector>
using namespace std;

int main() {
   int sync_with_stdio(false);
  

    int n; 
    cin >> n; 
    int lim = 100000; 
    vector<bool> is_prime(lim, true);
    for (int i = 2; i * i <= lim ; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= lim; j += i)
                is_prime[j] = false;

    vector<int> primes;
    for (int i = 2; i <= lim; ++i)
        if (is_prime[i]) primes.push_back(i);

    int index = primes[n-1];             
    int superprime = primes[index-1];    
    cout << superprime << "\n";
    return 0;
}
