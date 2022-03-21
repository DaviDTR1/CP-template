struct Flow_EK{

    void add(ll v, ll u, ll mpt){
        g[v].pb(u);
        g[u].pb(v);
        cap[v][u] = mpt;
        cap[u][v] = 0;
    }

    ll bfs(ll ini,ll fin, vi &path){
        fill(path.begin(), path.end(),-1);
        path[ini] = -2;
        queue<par> qp;
        qp.push({ini, INF});

        while(!qp.empty()){
            ll u = qp.front().first;
            ll flow = qp.front().second;
            qp.pop();
            rep(v, g[u]){
                if(path[v] == -1 && cap[u][v]){
                    path[v] = u;
                    ll new_flow = min(flow, cap[u][v]);
                    if(v==fin)return new_flow;
                    qp.push({v, new_flow});
                }
            }
        }
        return 0;
    }

    ll max_flow(ll ini, ll fin){
        ll flow = 0;
        vi path(fin+1);
        ll new_flow = 0;
        while((new_flow = bfs(ini,fin,path))){
            flow += new_flow;
            ll u = fin;
            while(u!=ini){
                ll tmp = path[u];
                cap[u][tmp] += new_flow;
                cap[tmp][u] -= new_flow;
                u = tmp;
            }
            cerr<<flow<<"\n";
        }
        return flow;
    }

}fw;