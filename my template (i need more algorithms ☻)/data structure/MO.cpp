/*distint number in an interval n * sqrt(n)*/

ll leng,t;
struct trio{
	ll l,r,id;
};
ll ar[100005];
ll cnt[1000005];
trio que[200005];

///sort query
bool cmp(trio &a,trio &b){
    if(a.l/leng!=b.l/leng)return a.l<b.l;
    return a.r < b.r;
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

void buildMO(){
    leng = sqrt(n);
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
}
