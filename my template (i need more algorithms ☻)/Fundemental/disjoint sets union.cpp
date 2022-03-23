ll ar[300005];
ll cnt[300005];
///path compression
ll parent(ll x){
    while(x != ar[x]){
        ar[x] = ar[ar[x]];
        x = ar[x];
    }
    return x;
}
///basic
void djs(ll a, ll b){
    a = parent(a);
    b = parent(b);
    if(a==b)return;
        if(cnt[a] > cnt[b])swap(a,b);
    ar[a] = b;
    cnt[b] += cnt[a];
}
///for other problems do not need path compression
void djs1(ll a, ll b){
    a = ar[a];
    b = ar[b];
    if(cnt[a].size() > cnt[b].size())swap(a,b);
    ar[a] = b;
    rep(i,cnt[a]){
        ar[i] = b;
        cnt[b].pb(i);
    }
    sum[a] = 0;
}
