#include <bits/stdc++.h>
using namespace std;

class DisJointSet{
    vector<int> parent;
    vector<int> rank;
    int n;
    public:
        DisJointSet(int n){
            this->n  = n;
            parent.resize(n+1);
            rank.resize(n+1,0);
            for(int i=0;i<=n;++i)
                parent[i]= i;
        }

        int findUPar(int u){
            if(parent[u]==u)
                return  parent[u];
            return parent[u]= findUPar(parent[u]);
        }

        void UnionByRank(int u,int v){
            int parentU = findUPar(u);
            int parentV = findUPar(v);

            if(parentU == parentV) return;

            int rankU = rank[parentU];
            int rankV = rank[parentV];

            if(rankU == rankV){
                // if both the ranks are similar just connect v to u.
                parent[parentV] = parentU;
                rank[parentU]++;
            }else if(rankU > rankV){
                parent[parentV] = parentU;
            }else{
                parent[parentU] = parentV;
            }
        }
};

/*
TEST CASE : 
1 - 2
2 - 3
4 - 5
3 - 4 
6 - 7
*/
int main()
{
    int V;
    cout<<"Enter the number of Nodes : ";
    cin>>V;

    DisJointSet ds(V);

    while(true){
        int u,v;

        int answer;
        cout<<"Enter 1 to Enter Edge || Enter 2 to check for any two nodes || Enter 3 to quit. : ";
        cin>>answer;
        
        if(answer==2){
            int a,b;
            cout<<"Enter the two nodes : ";
            cin>>a>>b;
            if(ds.findUPar(a)==ds.findUPar(b)){
                cout<<a<< " and " << "b belong to the same component"<<endl;
            }else{
                cout<<a<< " and " << "b belong to the different component"<<endl;
            }
        }else if(answer==1){
            int u,v;
            cout<<"Enter the Edge : ";
            cin>>u>>v;
            ds.UnionByRank(u,v);

        }else{
            break;
        }
    }
    return 0;
}