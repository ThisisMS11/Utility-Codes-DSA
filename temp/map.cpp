#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int> mp;
    mp.insert({1,2});
    mp.insert({4,5});
    mp.insert({3,5});

    for(auto it:mp){
        cout<<it.first<< " : "<<it.second<<endl;
        
    }

    string s = string(3,'a');
    cout<<s<<endl;
    return 0;
}