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
#define read(arr,n) for(ll i=0;i<n;++i) cin>>arr[i];
#define f first
#define s second
#define lb cout<<endl;
#define size(arr) sizeof(arr)/sizeof(int);
using namespace std;

//  4 = 100 5 = 101 =>  4^5 = 001 = 1 & 1 = something = true => different parity 
//  14 = 1110  7 = 111 =>  14^7= 1001 = 9 & 1 = > something = true => different parity
//  14 = 1110 4 =0100 => 14 ^ 4 = 1010 = 10 & 1 => nothing => false => same  parity.


void solve(){
    int n;
    cin>>n;

    vector<int> arr(n);
    int cnt = 0;

    int last = -1;
    fo(i,n){
        int temp ; 
        cin>>temp;
        if(last==-1) last= temp;
        else{
            // cout<<"last : "<<last<<" temp : "<<temp<<endl;
            // cout<<((last ^ temp)& 1)<<endl;

            if(((last ^ temp)& 1) == 0){
                /* same parity*/
                ++cnt;
                last = last * temp;
            }else{
                /* different parity*/
                last = temp;
            }
        }
    }

    cout<<cnt<<endl;
    // cout<<endl;
}


int32_t main()
{
    fastIO;
 
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

