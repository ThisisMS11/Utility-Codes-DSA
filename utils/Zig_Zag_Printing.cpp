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
#define substr(str,i,j) str.substr(i,j-i+1)
using namespace std;


void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    int tubeSize = 0, tubeNo = 0;
    vector<int> sizes(k);
    
    vector<vector<pair<int,int>>> table(k);

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int y ;
            if(i&1){
                /* i is an odd row*/
                y = m-j-1;
            }else{
                /* i is an even row*/
                y = j ;
            }
            ++tubeSize;
            table[tubeNo].push_back({i+1,y+1});
            if(tubeSize >=2 ){
                if(tubeNo!=k-1){
                    sizes[tubeNo]= tubeSize;
                    tubeNo++;
                    tubeSize = 0;
                }
            }
        }
    }

    sizes[k-1] = tubeSize;

    for(tubeNo=0;tubeNo<k;++tubeNo){
        cout<<sizes[tubeNo];
        for(auto it:table[tubeNo]){
            cout<<" "<<it.first<<" "<<it.second;
        }
        cout<<endl;
    }
}


int32_t main()
{
    fastIO;
 
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

