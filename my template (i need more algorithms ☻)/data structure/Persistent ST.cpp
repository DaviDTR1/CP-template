#define ll long long
ll R[4000005],L[4000005],st[4000005],root[100005];
ll ar[100005],n,k,br[100005],c;
queue<ll>pos[100005];

void update(ll l,ll r,ll riv,ll rev,ll x){
    ll mid = (l+r)>>1;
    if(l==r){
        st[riv] = st[rev]+1;
        return;
    }
    if(mid >=x){
        R[riv] = R[rev];
        L[riv] = ++c;
        update(l,mid,L[riv],L[rev],x);
    }
    else{
        L[riv] = L[rev];
        R[riv] = ++c;
        update(mid+1,r,R[riv],R[rev],x);
    }
    st[riv] = st[L[riv]] + st[R[riv]];
}

ll query(ll l,ll r,ll riv,ll rev,ll x){
    ll mid = (l+r)>>1;
    if(l > x)return 0;
    if(r <= x){
        return st[rev] - st[riv];
    }
    return query(l,mid,L[riv],L[rev],x) + query(mid+1,r,R[riv],R[rev],x);
}

void construct(){
    c = 0;
    for(ll i=1; i<= n;i++){
        root[i] = ++c;
        update(1,n+1,root[i],root[i-1],br[i]+1);
    }
}
