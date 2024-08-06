class Solution {
    public:
    int counter = 1;
    void dfs(vector<int>adj[],int node,int parent,vector<bool>&visited,vector<int>&tin,vector<int>&low
    ,vector<int>&isAp){
        
        visited[node] = true;
        tin[node] = low[node] = counter;
        ++counter;
        
        // going across the neighbors of node
        int child = 0;
        for(auto it:adj[node]){
            // increase the child counter;
            
            
            // if not visited.
            if(it==parent) continue;
            
            if(!visited[it]){
                dfs(adj,it,node,visited,tin,low,isAp);
                // check whether this can be aP or not.
                
                if(low[it]>=tin[node] && parent!=-1){
                    isAp[node] = 1;
                }
                // update the low of node.
                low[node] = min(low[it],low[node]);
                ++child;
                
            }else{
                // if already visited
                low[node] = min(low[node],tin[it]);
            }
        }
        
        if(child>1 && parent==-1)
            isAp[node] = 1;
        
    }
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> isAp(V,0);
        vector<bool>visited(V);
        vector<int>tin(V),low(V);
        
        dfs(adj,0,-1,visited,tin,low,isAp);
        
        vector<int> answer;
        for(int i=0;i<V;++i){
            if(isAp[i]){
                answer.push_back(i);
            }
        }
        
        if(answer.size()==0) return {-1};
            
        return answer;
    }
};