class Solution {
public:
    
    int parent[100005];
    int rank[100005];
    
    void mySet(int sz){
        for(int i = 0;i<sz;i++){
            parent[i] = i;
            rank[i]   = 1;
        }
    }
    
    int findPar(int u){
        if(parent[u] == u)
            return parent[u];
        return parent[u] = findPar(parent[u]);    
    }
    
    void merge(int u, int v){
        
        int par1 = findPar(u);
        int par2 = findPar(v);
        
        if(par1!=par2){
                if(rank[par1]>rank[par2])
                    parent[par2] = par1;
                else if(rank[par1]<rank[par2]){
                    parent[par1] = par2;
                }else{
                    parent[par2] = par1;
                    rank[par1]++;
                }
            }     
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(n-1 > connections.size()) // (For n nodes it is required that we                                          ////////////////////should have n-1 edges)
            return -1;
        
        mySet(n);
      

        for(auto &connection:connections){
            
            int u = connection[0];
            int v  = connection[1];
            
            int par1 = findPar(u);
            int par2 = findPar(v);
            
            if(par1!=par2)
            merge(u,v);

        }
        
        int comp = 0;
        
        for(int i = 0;i<n;i++){
            if(parent[i] == i){
                comp++;
            }
        }
        
        return comp-1;    /// we count the components that are in the graph,for 
                         // n components it is required to have n-1 edges;
    }
};