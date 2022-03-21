
struct Flow_Edge{
    ll v,u;
    ll cap,flow=0;
    Flow_Edge(ll v,ll u,ll cap):v(v), u(u), cap(cap){}
};
vector<Flow_Edge>edges;
vi g[505];
vi lv, parent;
ll ct=0,s,t;
queue<ll>qp;

struct DINIC{

    void add(ll v, ll u,ll cap){
        edges.emplace_back(v,u,cap);
        edges.emplace_back(u,v,0);
        g[v].pb(ct);
        g[u].pb(ct+1);
        ct+=2;
    }

    bool bfs(){
        while(!qp.empty()){
            ll u = qp.front();
            qp.pop();
            rep(v, g[u]){
                if(edges[v].cap - edges[v].flow<1)continue;
                if(lv[edges[v].u]!=-1)continue;
                lv[edges[v].u] = lv[u] + 1;
                qp.push(edges[v].u);
            }
        }
        return lv[t] != -1;
    }

    ll dfs(ll u, ll p){
        if(p==0)return 0;
        if(u==t)return p;
        ll ta = g[u].size();

        for(ll& c = parent[u]; c < ta;c++){
            ll id = g[u][c];
            ll v = edges[id].u;
            if(lv[u]+1 != lv[v] || edges[id].cap - edges[id].flow<1)continue;
            ll tr = dfs(v, min(p, edges[id].cap-edges[id].flow));
            if(tr==0)
                continue;
            edges[id].flow += tr;
            edges[id^1].flow -= tr;
            return tr;
        }
        return 0;
    }
    ll flow(){
        ll f = 0;
        while(1){
            fill(lv.begin(),lv.end(),-1);
            lv[s] = 0;
            qp.push(s);
            if(!bfs())break;
            fill(parent.begin(), parent.end(),0);
            while (ll p = dfs(s, INF)){
                f+= p;
            }
        }
        return f;
    }
}fw;

