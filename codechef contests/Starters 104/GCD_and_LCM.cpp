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


int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
}

// Function to return LCM of two numbers  
int lcm(int a, int b) 
{ 
    return (a / gcd(a, b)) * b; 
} 

void solve(){
    int x,y,k;
    cin>>x>>y>>k;

    int temp1= gcd(x,y);
    int temp= min(x,y);

    if(k<=1){
        cout<<temp1 + temp <<endl;
        return ; 
    }

    int temp3 = lcm(temp1,temp);
    temp = min(temp1,temp);

    cout<<temp3 + temp<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // int t;
    // cin>>t;
    // while(t--){
    //     solve();
    // }

    cout<<lcm(24,16)<<endl;
    return 0;
}