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
    if(n==1 || n%2==0){
        cout<<"YES"<<endl;
        return ;
    }
    cout<<"NO"<<endl;
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