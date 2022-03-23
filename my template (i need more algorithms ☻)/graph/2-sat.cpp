vi gt[200005],g[200005];
vi order, comp[200005];
vi val(200005);
ll id[200005];
bool mark[200005];
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
    id[u] = c;
    comp[c].push_back(u);
    rep(v, gt[u]){
        if(!mark[v])dfs2(v,c);
    }
}
bool build(){
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
    ///solve 2-sat
    for(ll i = 2;i <= n; i+= 2){
        if(id[i]==id[i-1])return false;
        val[i/2] = id[i-1] > id[i]; 
    }
    
    return 1;
}