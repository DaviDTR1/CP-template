/// problems in the form dp(i,j) = min (dp(i-1,k) + C(k,j))    k <= j
vi dpb(n+1), dpc(n+1);
ll C[m+1][m+1];

void compute(ll l, ll r, ll optl, ll optr){
	if(l > r)return;
	ll mid = (l+r)>>1;
	par best = {INF,-1};
	for(ll k = optl; k <= min(mid, optr); k++){
		best = min(best, {dpb[k] + C[k][mid], k});
	}
	
	dpc[mid] = best.first;
	ll opt = best.second;
	
	compute(l,mid-1, optl, opt);
	compute(mid+1,r, opt, optr);
}	