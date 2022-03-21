struct be_ford{
    ll path[5005];
    ll negidx;
    bool spfa(ll ini){
        vi cnt(n+1, 0);
        vector<bool>inqueue(n+1, 0);
        queue<ll> qp;
        qp.push(ini);
        dp[ini] = 0;
        
        while(!qp.empty()){
            ll u = qp.front();
            qp.pop();
            inqueue[u] = 0;
            rep(v,g[u]){
                if(dp[u] + v.y1 < dp[v.x1]){
                    dp[v.x1] = dp[u] + v.y1;
                    path[v.y1] = u;
                    if(!inqueue[v.y1]){
                        qp.push(v.y1);
                        inqueue[v.y1] = 1;
                        cnt[v.y1]++;
                        if(cnt > n){
                            negidx = v.y1;
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }

    void bellman_ford(ll ini){
        dp[ini] = 0;
        bool any = 0;
        fr(x,1,n-1){
            any = 0;
            rep(v,g){
                if(dp[v.b] > dp[v.a] + v.val){
                    dp[v.b] = dp[v.a] + v.val;
                    path[v.b] = v.a;
                    any = 1;
                }
            }
            if(!any)break;
        }
    }
    bool neg_cicl(){
        negidx = -1;
        rep(v,g){
            if(dp[v.b] < dp[v.a] + v.val){
                negidx = v.b;
                dp[v.b] = dp[v.a] + v.val;
            }
        }
        if(negidx!=-1)return 1;
        return 0;
    }

}bf;