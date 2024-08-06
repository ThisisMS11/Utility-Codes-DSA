#include <bits/stdc++.h>
using namespace std;

bool is_Prime(int n){
    bool flag = true;
    for(int i=2;i*i<=n;++i){
        if(n % i ==0){
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    int n;
    cin>>n;

    cout<<is_Prime(n)<<endl;
    return 0;
}