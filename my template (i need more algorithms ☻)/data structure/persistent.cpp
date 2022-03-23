ll n,t;
ll L[300005 * 25],R[300005 * 25], st[300005 * 25],root[300005];
ll id;
ll ar[300005];;

void upd(int act, int ant, int l,int r,int k){
    st[act] = st[ant]+1;
    if(l==r){
        return;
    }
    int m = (l+r)>>1;
    if(m>=k){
        L[act] = ++id;
        R[act] = R[ant];
        upd(L[act], L[ant], l, m, k);
    } else{
        R[act] = ++id;
        L[act] = L[ant];
        upd(R[act], R[ant], m+1, r, k);
    }
}

int query(int act, int ant, int l, int r, int k){
	if(l == r)
		return st[act] - st[ant];
	int m = (l+r)>>1;
	int count = st[L[act]] - st[L[ant]];
	if(m >= k)
		return query(L[act], L[ant], l, m, k);
	return count + query(R[act], R[ant], m+1, r, k);
}

void build(){
	fr(i,1,n){
        root[i] = ++id;
        upd(root[i], root[i-1], 1, maxm, as[ar[i]]);
    }
}