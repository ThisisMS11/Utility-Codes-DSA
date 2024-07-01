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
#define size(arr) sizeof(arr)/sizeof(int);
using namespace std;


void solve(){
    int n;
    cin>>n;

    vector<int> arr(n);
    fo(i,n){
        cin>>arr[i];
    }
    vector<int> lse(n),rse(n);
    lse[0] = -1, rse[n-1] = -1;

    /* for find left smallest index*/
    fo1(i,n){
        if(lse[i-1]==-1){
            lse[i] = i-1;
        }else{
            if(arr[lse[i-1]] < arr[i-1]){
                lse[i] = lse[i-1];
            }else{
                lse[i] = i-1;
            }
        }

        if(rse[n-i]==-1){
            rse[n-i-1] = n-i;
        }else{
            if(arr[rse[n-i]] < arr[n-i]){
                rse[n-i-1] = rse[n-i];
            }else{
                rse[n-i-1] = n-i;
            }
        }
    }
    
    // cout<<"LSE[] :";
    // fo(i,n){
    //     cout<<lse[i]<<" ";
    // }
    // cout<<endl;

    // cout<<"RSE[] :";
    // fo(i,n){
    //     cout<<rse[i]<<" ";
    // }
    // cout<<endl;

    for(int i=1;i<n-1;++i){
        if(arr[lse[i]] < arr[i] && arr[i] > arr[rse[i]]){
            cout<<"YES"<<endl;
            cout<<lse[i]+1<<" "<<i+1<<" "<<rse[i] + 1<<endl;
            return ;
        }
    }
    cout<<"NO"<<endl;
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

