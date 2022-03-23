bool mark[10005];
ll mt[10005];

bool try_kunh(ll u){
    if(mark[u])
        return 0;
    mark[u] = 1;
    rep(v, g[u]){
        if(mt[v]==-1 || try_kunh(mt[v])){
            mt[v] = u;
            return 1;
        }
    }
    return 0;
}
void comp(){
    fill(mt+1,mt+n+1,-1);
    vector<bool>used(n+1);
    fr(i,1,n){
        rep(v, g[i]){
            if(mt[v]==-1){
                mt[v] = i;
                used[i] = 1;
                break;
            }
        }
    }
    fr(i,1,n){
        if(used[i])continue;
        fill(mark+1,mark+n+1,0);
        try_kunh(i);
    }
}
