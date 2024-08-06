#include <bits/stdc++.h>
using namespace std;

// Function to find divisors of a number n using sqrt(n)
vector<int> findDivisors(int n) {
    vector<int> divisors;

    // Iterate from 1 to sqrt(n)
    for (int i = 1; i <= sqrt(n); ++i) {
        // If i is a divisor of n
        if (n % i == 0) {
            // If the divisors are the same, only add it once (for perfect squares)
            if (n / i == i) {
                divisors.push_back(i);
            } else {
                // Add both divisors
                divisors.push_back(i);
                divisors.push_back(n / i);
            }
        }
    }

    return divisors;
}

vector<ll> findDivisors(ll x){
    vector<pair<int,int>> prime_divisors;

    for(int i=2;i*i<=x;++i){
        if(x % i==0){
            int cnt = 0;
            while(x % i ==0){
                ++cnt;
                x/=i;
            }
            prime_divisors.push_back({i,cnt});
        }
    }
    return prime_divisors;
}

int main()
{
    
    return 0;
}