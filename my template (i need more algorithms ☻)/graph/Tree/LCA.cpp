
ll lv[100005];
vi g[100005];
ll lca[100005][25];

void buildLCA(ll root){
	queue<par> qp;
	qp.push({root,root});
	while(!qp.empty()){
		ll u = qp.front().first;
		ll p = qp.front().second;
		qp.pop();
		
		lv[u] = lv[p]+1;
		ll z = 31-__builtin_clz(lv[u]);
		lca[u][0] = p;
		fr(i,1,z){
			lca[u][i] = lca[lca[u][i-1]][i-1];
		}

		rep(v, g[u]){
			if(v==p)continue;
			qp.push({v,u});
		}
	}
}

ll find_lca(ll x, ll y){
	if(lv[x] < lv[y])swap(x,y);
	ll z = 31-__builtin_clz(lv[x]);
	for(ll i = z; i>=0;i--){
		if(lv[x]-(1<<i) >= lv[y]){
			x = lca[x][i];
		}
	}
	if(x==y)return x;
	for(ll i = z; i>=0;i--){
		if(lca[x][i] != lca[y][i]){
			x = lca[x][i];
			y = lca[y][i];
		}
	}
	return lca[x][0];
}
