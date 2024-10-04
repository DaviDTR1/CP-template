vi dfs_num, dfs_low, dfs_parent, articulation_vertex,vec[100001];
set<par>bridges;
int dfsNumberCounter, dfsRoot, rootChildren;
void articulationPointAndBridge(int u) {
dfs_num[u] = dfsNumberCounter++;
dfs_low[u] = dfs_num[u]; // dfs_low[u]<=dfs_num[u]
for (auto v : vec[u]) {
if (dfs_num[v] == -1) { // a tree edge
dfs_parent[v] = u;
if (u == dfsRoot) ++rootChildren; // special case, root
articulationPointAndBridge(v);
if (dfs_low[v] >= dfs_num[u]) // for articulation point
articulation_vertex[u] = 1; // store this info first
if (dfs_low[v] > dfs_num[u]){ // for bridge
///printf(" (%d, %d) is a bridge\n", u, v);
bridges.insert({u,v});
}
dfs_low[u] = min(dfs_low[u], dfs_low[v]); // subtree, always update
}
else if (v != dfs_parent[u]) // if a non-trivial cycle
dfs_low[u] = min(dfs_low[u], dfs_num[v]); // then can update
}
}
// inside int main()
    dfs_num.assign(n+1, -1); dfs_low.assign(n+1, 0);
    dfs_parent.assign(n+1, -1); articulation_vertex.assign(n+1, 0);
    dfsNumberCounter = 0;
    dfsRoot = 1; rootChildren = 0;
    articulationPointAndBridge(1);
    articulation_vertex[dfsRoot] = (rootChildren>1);
