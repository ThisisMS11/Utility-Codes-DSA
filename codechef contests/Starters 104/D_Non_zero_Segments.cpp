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
    ll n; 
    cin>>n;
    unordered_set<ll> st;
    ll sum = 0;
    ll cnt = 0;
    st.insert(0);

    fo(i,n){
        int temp ;
        cin>> temp;
        sum +=temp;

        if(st.find(sum)!=st.end()){
            ++cnt;
            st.clear();
            st.insert(temp);
            st.insert(0);
            sum = temp;
        }
        else 
            st.insert(sum);
    }
    cout<<cnt<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}