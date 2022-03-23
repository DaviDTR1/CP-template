ll markU[10005];
ll markV[10005];
ll lv[10005];
ll match=0;

bool bfs(){
    queue<ll>qp;
    fr(i,1,n){
        if(!markU[i]){
            lv[i] = 0;
            qp.push(i);
        } else lv[i] = INF;
    }
    lv[0] = INF;
    while(!qp.empty()){
        ll u = qp.front();
        qp.pop();
        if(lv[u] == lv[0])continue;
        rep(v, g[u]){
            if(lv[markV[v]]==INF){
                lv[markV[v]] = lv[u]+1;
                qp.push(markV[v]);
            }
        }
    }
    return lv[0] != INF;
}
///max matching
bool dfs(ll u){
    if(u==0)
        return 1;
    rep(v, g[u]){
        if(lv[markV[v]] == lv[u]+1){
            if(dfs(markV[v])){
                markV[v] = u;
                markU[u] = v;
                return 1;
            }
        }
    }
    lv[u] = INF;
    return 0;
}

void comp(){
    fr(i,1,n){
        markU[i] = 0;
        markV[i] = 0;   
    }
    while(bfs()){
        fr(i,1,n){
            if(markU[i])continue;
            if(dfs(i))match++;
        }
    }
}

