// this is kruskal alg to find mst 
#include <bits/stdc++.h>
using namespace std;


class DSU{
   vector<int>rank;
   vector<int>par;
   vector<int>size;

   DSU(int n ){
    rank.resize(n+1,0);
    par.resize(n+1);
    size.resize(n+1)
    for(int i =0;i<n;i++){
        par[i]=i;
        size[i]=1;
    }
   }
   int findPar(int node){
    if(par[node] == node)return node;
    return par[node] = findPar(par[node]);
   }
   void unionByRank(int u,int v){
     int uu_p = findPar(u);
     int vu_p = findPar(v);
     if(uu_p == vu_p)return;

     if(rank[uu_p] == rank[vu_p]){
        par[vu_p]=uu_p;
        rank[uu_p]++;
     }
     else if(rank[uu_p] > rank[vu_p]){
        par[vu_p] = uu_p;
     }else{
        par[uu_p] = vu_p;
     }
   }
   void unionBySize(int u, int v) {
    int ulp_u = findPar(u);
    int ulp_v = findPar(v);
    if (ulp_u == ulp_v) return;
    if (size[ulp_u] < size[ulp_v]) {
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];
    }
    else {
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
}
};
class Solution
{
public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // 1 - 2 wt = 5
        /// 1 - > (2, 5)
        // 2 -> (1, 5)

        // 5, 1, 2
        // 5, 2, 1
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        DSU ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findPar(u) != ds.findPar(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }
};
int main(){
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }
    Solution obj;
    int mstweight = obj.spanningTree(V,adj);
    cout<< "This is the mst weight : " << mstweight << endl;

    return 0;
}