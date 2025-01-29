class DisjointSet{
    public:
    vector<int> parent,rank;
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    bool unionByRank(int u,int v){
        int ulp_v = findUPar(v);
        int ulp_u = findUPar(u);
        if(ulp_v == ulp_u) return false;
        if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        for(auto it:edges){
                if(!ds.unionByRank(it[0],it[1])){
                    return {it[0],it[1]};
                }
        }
        return {};
    }
};