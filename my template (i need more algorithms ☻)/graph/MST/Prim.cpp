struct trio{
    ll nod,parent,val;
    bool operator < (const trio &a)const{
        return val > a.val;
    }
};
vector<par> g[500005];
vector<par> sol[500005];

int prim(){
    priority_queue<trio>qp;
    qp.push({1,0,0});
    vector<bool> vis(n+1);
    ll res = 0;
    while(!qp.empty()){
        ll val = qp.top().val;
        ll u = qp.top().nod;
        ll p = qp.top().parent;
        qp.pop();
        if(vis[u])continue;
        vis[u] = 1;
        if(p!=0){
            g[p].pb({u,val});
            g[u].pb({p,val});
        }
        res += val;
        rep(v, g[u]){
            if(vis[v.x1])continue;
            qp.push({v.x1,u,v.y1});
        }
    }
    return res;
}