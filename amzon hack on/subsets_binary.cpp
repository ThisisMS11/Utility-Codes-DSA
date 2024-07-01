#include <bits/stdc++.h>
#define fo(i, n) for (ll i = 0; i < n; i++)
#define fo1(i, n) for (ll i = 1; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define p(k) cout << k <<endl;
#define i(k) cin >> k;
#define slen(k) strlen(k);
#define ll long long int
#define pb push_back
#define unsigned long long int ulli
#define mod 1000000007
#define pii pair<int, int>
#define f first
#define s second
#define lb cout<<endl;
using namespace std;

unordered_map<string, int> dp;

int f(vector<int>& arr, int index, int sum, int k) {
    if (index == arr.size()) {
        int cnt = 0;
        for (int i = 0; i < 32; ++i) {
            if ((sum & (1 << i))) ++cnt;
        }
        return cnt == k ? 1 : 0;
    }

    string key = to_string(index) + "|" + to_string(sum);
    if (dp.find(key) != dp.end()) return dp[key];

    /* not choosing index */
    int notChoose = f(arr, index + 1, sum, k);

    /* choosing index */
    int choose = f(arr, index + 1, sum + arr[index], k);

    dp[key] = choose + notChoose;
    return dp[key];
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    fo(i, n) cin >> arr[i];

    dp.clear();
    int result = f(arr, 0, 0, k);
    cout << result << endl;
}

int32_t main() {
    fastIO;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
