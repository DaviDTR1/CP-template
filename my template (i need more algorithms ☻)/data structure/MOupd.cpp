/*distint number in an interval with updates */ 
ll leng,t;
struct trio{
	ll l,r,id,time;
};
struct  par{
    ll id,val;
};
ll ar[100005];
ll cnt[1000005];
trio que[200005];
par updates[200005];
///sort query
bool cmp(trio &a,trio &b){
    if(a.l/leng!=b.l/leng)return a.l<b.l;
    if(a.r/leng!=b.r/leng){
	if((a.l/leng)%2)
	    return a.r<b.r;
	else
	    return a.r>b.r;
    }
    return a.time < b.time;
}

ll res;
///remove element
void rem(ll u){
	cnt[ar[u]]--;
	if(cnt[ar[u]]==0){
	    res--;
	}
}
///add element
void add(ll u){
	cnt[ar[u]]++;
	if(cnt[ar[u]]==1){
	    res++;
	}
}
///update elements
void up(ll u,ll l, ll r){
    ll pos = updates[u].id;
    if(l <= pos && pos <= r){
        cnt[ar[pos]]--;
        cnt[updates[u].val]++;
    }
    swap(ar[pos],updates[u].val);
}

void buildMO(){
    leng = cbrt(2*n*n);
    sort(que+1,que+t+1,cmp);
    vi sol(t+1);
    ll l=1,r=0,c_t = 0;
    fr(i,1,t){
        ll x = que[i].l;
        ll y = que[i].r;
        ll z = que[i].time;
        while(c_t < z){
            c_t++;
            up(c_t,l,r);
        }
        while(c_t > z){
            up(c_t,l,r);
            c_t--;
        }
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
}
