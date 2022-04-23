
ll gilbertOrder(ll x,ll y,ll pot,ll rotate){
    if(pot==0){
        return 0;
    }
    ll hpot = 1 << (pot-1);
    ll seg = (x< hpot) ? (y < hpot ? 0 : 3) : (y < hpot ? 1 : 2);
    seg = (seg+rotate) &3;
    const ll rotateDelta[4] = {3,0,0,1};
    ll  nx = x & (x ^ hpot), ny = y & (y ^ hpot);
    ll nrot = (rotate + rotateDelta[seg]) & 3;
    ll subsquaresize = 1LL<<(2*pot+2);
    ll ans = seg * subsquaresize;
    ll add = gilbertOrder(nx, ny, pot-1,nrot);
    ans += (seg==1 || seg==2) ? add : (subsquaresize-add-1);
    return ans;
}

struct trio{
	ll l,r,id,ord;

    void calcOrder(){
        ord = gilbertOrder(l,r,21,0);
    }
};
ll ar[100005],cnt[1000005];
trio que[200005];

///sort query
bool cmp(trio &a,trio &b){
    return a.ord < b.ord;
}

ll res;
///remove element
void rem(ll u){
    cnt[ar[u]]--;
}
///add element
void add(ll u){
    cnt[ar[u]]++;
}

void buildMO(){
    sort(que+1,que+t+1,cmp);
    vi sol(t+1);
    ll l=1,r=0;
    fr(i,1,t){
        ll x = que[i].l;
        ll y = que[i].r;
        while(l<x){
            rem(l);
            l++;
        }
        while(l>x){
            l--;
            add(l);
        }
        while(r<y){
            r++;
            add(r);
        }
        while(r>y){
            rem(r);
            r--;
        }
        sol[que[i].id] = res;
    }
    ///fr(i,1,t)cout<<sol[i]<<"\n";
}
