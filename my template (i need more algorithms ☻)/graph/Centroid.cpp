#define t_max 100005

struct Centroid_D{
    vi gc[t_max];
    ll lv[t_max],sub[t_max],parent[t_max];
    bool mark[t_max];

    void dfs(ll u,ll p){
        sub[u] = 1;
        if(!lv[u]){
            lv[u] = lv[p]+1;
        }
        rep(v,g[u]){
            if(mark[v] || v==p)continue;
            dfs(v, u);
            sub[u] += sub[v];
        }
    }

    ll find_c(ll u,ll p,ll tam){
        rep(v,g[u]){
            if(mark[v] || v==p)continue;
            if(sub[v] >= tam)return find_c(v, u, tam);
        }
        return u;
    }

    void centroid_d(ll x, ll p){
        ll tam = sub[x];
        ll cent = find_c(x,x,tam);
        mark[cent] = 1;
        parent[cent] = p;
        gc[p].pb(cent);

        rep(v ,g[cent]){
            if(mark[v])continue;
            dfs(v,v);    
            centroid_d(v, cent);
        }
    }

}c_d;