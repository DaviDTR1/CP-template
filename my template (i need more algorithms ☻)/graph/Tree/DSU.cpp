///DSU on Trees
int n;
vector<int>g[1000001];
int sol[1000001];
int soli[1000001];
int cnt[1000001],lv[1000001],sub[1000001];
int maxsub[1000001];
bool big[1000001];
 
void getsub(int v,int p){
    ///obtener el tamaño de los subarboles y ver cual es el hijo mas grande
    sub[v] = 1;
    rep(u,g[v]){
        if(u==p)continue;
        lv[u] = lv[v]+1;
        getsub(u,v);
        sub[v] += sub[u];
        if(sub[maxsub[v]] < sub[u])maxsub[v] = u;
    }
}
 
void add(int v,int p,int x,int root){
	///Calcular el subarbol normalmente esta es la funcion q se modifica
    if(x==1) {
        cnt[lv[v]]++;
        if(cnt[lv[v]] == soli[root] && sol[root] > lv[v]){
            sol[root] = lv[v];
        }
        if(cnt[lv[v]] > soli[root]){
            soli[root] = cnt[lv[v]];
            sol[root] = lv[v];
        }
    }
    else{
        cnt[lv[v]]--;
    }
    rep(u,g[v])
        if(u!=p && !big[u])
            add(u,v,x,root);
 
}
 
void dfs(int v,int p,bool keep){
	///moverse en el arbol calculando los hijos y dejando de ultimo el mayor hijo
    rep(u,g[v])if(u!=p && u!=maxsub[v])dfs(u,v,0);
    if(maxsub[v]){dfs(maxsub[v],v,1);big[maxsub[v]] = 1;}
    if(soli[maxsub[v]]>1){
        sol[v] = sol[maxsub[v]];
        soli[v] = soli[maxsub[v]];
    }
    add(v,p,1,v);
    if(maxsub[v])big[maxsub[v]] = 0;
    if(!keep)add(v,p,-1,v);
}