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

unordered_map<string, int> memo;

int f(vector<int>& arr, vector<int>& temp, int index, int sum, int l, int r, int x){
    if(index == arr.size()){
        int n = temp.size();
        if(n < 2 || (arr[n-1] - arr[0] < x) || !(sum >= l && sum <= r))
            return 0;
        return 1;
    }
    
    string key = to_string(index) + "-" + to_string(sum);
    for(int i = 0; i < temp.size(); i++) key += "-" + to_string(temp[i]);
    
    if(memo.find(key) != memo.end()) return memo[key];
    
    /* not choosing index */
    int notChoose = f(arr, temp, index + 1, sum, l, r, x);
    
    /* choosing index */
    temp.push_back(arr[index]);
    int choose = f(arr, temp, index + 1, sum + arr[index], l, r, x);
    temp.pop_back();
    
    memo[key] = choose + notChoose;
    return memo[key];
}

void solve(){
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    
    vector<int> arr(n);
    fo(i, n){
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end(;))
    
    vector<int> temp;
    int result = f(arr, temp, 0, 0, l, r, x);
    cout << result << endl;
}

int32_t main()
{
    fastIO;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
