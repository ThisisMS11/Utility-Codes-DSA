#include <bits/stdc++.h>
#define fo(i, n) for (ll i = 0; i < n; i++)
#define fo1(i, n) for (ll i = 1; i <= n; i++)
#define p(k) cout << k <<endl;
#define i(k) cin >> k;
#define slen(k) strlen(k);
#define ll long long int
#define unsigned long long int ulli
#define mod 1000000007
#define size(arr) sizeof(arr)/sizeof(int);
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);

    fo(i,n){
        cin>>arr[i];
    }

    vector<int> prefix(n);
    prefix[0]= arr[0];
    for(int i=1;i<n;++i){
        prefix[i] = max(prefix[i-1],arr[i]);
    }

    vector<int> suffix(n);
    suffix[n-1]= arr[n-1];
    for(int i=n-2;i>=0;--i){
        suffix[i] = max(suffix[i+1],arr[i]);
    }

    long long answer = 0;
    fo(i,n){
        answer += min(prefix[i],suffix[i]);
    }
    cout<<answer<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}