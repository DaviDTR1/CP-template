///Compresion de cordenadas O(N log n) query O(1)
map<ll,ll>as;
///para cada indice del arreglo se le asigna un valor
///para preguntar por un numero se pregunta por el indice en el arreglo q se encuentra
ll posi[1000005];
void build(ll n){
    vi ar(n+1);
    fr(i,1,n){
        cin>>ar[i];
        as[ar[i]];
    }
    ll conti=0;
    rep(v, as){
        conti++;
        as[v.first] = conti;
    }
    fr(i,1,n){
        posi[i] = as[ar[i]];
    }
}
