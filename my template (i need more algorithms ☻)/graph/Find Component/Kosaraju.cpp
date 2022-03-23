vi gt[105],g[105];
vi order, comp[105];
vi gc[105];
ll id[105];
map<ll,bool>mat[105];
bool mark[105];
///topsort
void dfs1(ll u){
    mark[u] = 1;
    rep(v, g[u]){
        if(!mark[v])dfs1(v);
    }
    order.push_back(u);
}
///FIND SCC
void dfs2(ll u, ll c){
    mark[u] = 1;
    ar[u] = c;
    comp[c].push_back(u);
    rep(v, gt[u]){
        if(!mark[v])dfs2(v,c);
    }
}
ll build(){
    ///topsort
    fr(i,1,n){
        if(!mark[i])dfs1(i);
    }
    fill(mark,mark+n+1,0);
    ll c = 0;
    reverse(order.begin(),order.end());
    ///FIND SCC
    rep(i, order){
        if(!mark[i])dfs2(i,++c);
    }
    fill(mark,mark+n+1,0);
    ///Create COndesation Graph (acyclic)
    fr(i,1,c){
        mat[i][i] = 1;
        rep(u, comp[i]){
            rep(v,g[u]){
                if(!mat[i][ar[v]]){
                    gc[i].pb(ar[v]);
                    mat[i][ar[v]] = 1;
                    mark[ar[v]] = 1;
                }
            }
        }
    }
    return c;
}