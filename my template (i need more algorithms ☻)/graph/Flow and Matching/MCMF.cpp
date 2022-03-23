ll n,t,ct;
vi g[2205];

struct Flow_Edge{
    ll v,u;
    ll cap,cost,rev,flow=0;
    Flow_Edge(ll v,ll u,ll cap,ll cost, ll rev):v(v), u(u), cap(cap), cost(cost), rev(rev){}
};
vector<Flow_Edge>edges;

///create the edges
void add(ll v, ll u,ll cap, ll val){
    edges.emplace_back(v,u,cap,val,ct+1);
    edges.emplace_back(u,v,0,-val,ct);
    g[v].pb(ct);
    g[u].pb(ct+1);
    ct+=2;
}

///for graph without negative cylces
bool dijkstra(ll ini,ll fin,vi &path,vi &d){
    fill(d.begin(), d.end(),INF);
    fill(path.begin(), path.end(),-1);
    d[ini] = 0;
    priority_queue<par, vector<par>,greater<par> >qp;
    qp.push({0,ini});
    while(!qp.empty()){
        par v = qp.top();
        qp.pop();
        if(v.second==fin)return 1;
        rep(c, g[v.second]){
            ll val = v.first + edges[c].cost;
            ll u = edges[c].u;
            if(val < d[u] && edges[c].flow < edges[c].cap){
                path[u] = c;
                d[u] = val;
                qp.push({d[u],u});
            }
        }
    }
    return 0;
}

///All graph
void spfa(ll ini,ll fin, vi &path, vi &d){
    fill(d.begin(), d.end(),INF);
    fill(path.begin(), path.end(),-1);
    d[ini] = 0;
    vector<bool>inq(fin+1,0);
    queue<ll> qp;
    qp.push({ini});

    while(!qp.empty()){
        ll u = qp.front();
        qp.pop();
        inq[u] = 0;
        rep(c, g[u]){
            ll v = edges[c].u;
            if(edges[c].cap > edges[c].flow && d[v]>d[u] + edges[c].cost){
                d[v] = d[u] + edges[c].cost;
                path[v] = c;
                if(!inq[v]){
                    inq[v] = 1;
                    qp.push(v);
                }
            }
        }
    }
}

ll max_flow(ll ini, ll fin, ll K){
    ll flow = 0;
    ll cts = 0;
    vi path(fin+1);
    vi d(fin+1);
    while(flow < K){
        dijkstra(ini,fin,path,d);
        if(d[fin]==INF)break;
        ll new_flow = K-flow;
        ll u = fin;
        while(u!=ini){
            ll tmp = path[u];
            new_flow = min(new_flow,edges[tmp].cap-edges[tmp].flow);
            u = edges[tmp].v;
        }
        flow += new_flow;
        cts += new_flow*d[fin];
        u = fin;
        while(u!=ini){
            ll tmp = path[u];
            edges[tmp].flow += new_flow;
            edges[edges[tmp].rev].flow -= new_flow;
            u = edges[tmp].v;
        }
    }
    return cts;
}