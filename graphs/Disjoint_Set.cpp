#include <bits/stdc++.h>
using namespace std;

class DisJointSet{
    vector<int> parent;
    vector<int> rank;
    public:
        DisJointSet(int n){
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

int main()
{
    int V,E;
    cin>>V>>E;
    vector<vector<int>> edges(E,vector<int>(2));
    for(int i=0;i<E;++i){
        int u,v;
        cin>>u>>v;
        edges[i][0] = u;
        edges[i][1] = v;
    }

    DisJointSet ds(V); 
    for(auto it:edges){
        int u = it[0] , v = it[1];
        
        if(ds.findUPar(u)==ds.findUPar(v)){
            cout<<u << " and "<<v<<" both have the same parent .";
        }else{
            cout<<u << " and "<<v<<" both have the different parent .";
        }

        ds.UnionByRank(u,v);
    }
    return 0;
}