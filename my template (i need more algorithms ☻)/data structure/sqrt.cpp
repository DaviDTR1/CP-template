ll ar[maxn],sq[qrt],ini[qrt],fin[qrt];
int g[maxn];

void build(){
    int group = 1;
    ll x = sqrt(n);
    ini[1] = 1;
    fr(i,1,n){
        g[i] = group;
        sq[group] = min(sq[group],ar[i]);
        if(i%x==0){
            fin[group] = i;
            group++;
            ini[group] = i+1;
        }
    }
    fin[group] = n;
}

void update(ll x,ll val){
    ar[x] = val;
    sq[g[x]] = INF;
    fr(i,ini[g[x]],fin[g[x]]){
        sq[g[i]] = min(sq[g[i]],ar[i]);
    }
}

ll query(ll l,ll r){
    ll i = l;
    ll res = INF;
    for(;g[i]==g[l] && i<=r;i++)
        res = min(res, ar[i]);
    for(;g[i]!=g[r];i = ini[g[i]+1])
        res = min(sq[g[i]],res);
    for(;i<=r;i++)
        res = min(res, ar[i]);
    return res;
}