ll id[500005];
ll cnt[500005];

ll parent(ll x){
    while(x != id[x]){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void djs(ll a, ll b){
    a = parent(a);
    b = parent(b);
    if(a==b)return;
        if(cnt[a] > cnt[b])swap(a,b);
    id[a] = b;
    cnt[b] += cnt[a];
}

struct edges{
    ll v,u;
    ll val;
    bool operator <(const edges &a)const{
        return a.val > val;
    }
};
vector<edges>g;
vector<par>sol;

int kruskal(){
    fr(i,1,n){id[i] = i;cnt[i]++;}
    sort(g.begin(),g.end());
    ll res = 0;
    rep(v, g){
        if(parent(v.v) != parent(v.u)){
            djs(v.v,v.u);
            res += v.val;
            sol[v.v].pb({v.u,v.val});
            sol[v.u].pb({v.v,v.val});
        }
    }
    return res;
}