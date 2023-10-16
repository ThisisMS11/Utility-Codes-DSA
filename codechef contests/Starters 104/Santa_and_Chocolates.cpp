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
    int n,k;
    cin>>n>>k;

    int total = 0;
    fo(i,n){
        int temp;
        cin>>temp;
        total += temp;
    }

    if(total < n){
        cout<<"NO"<<endl;
        return ;
    }

    int rem = total % n;
    if(rem!=0 && k==0){
        cout<<"NO"<<endl;
        return ;
    }
    cout<<"YES"<<endl;
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