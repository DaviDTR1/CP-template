ll spg[10005];

ll buildSPG(ll x){
    if(spg[x] != -1)return spg[x];
	vector<bool>s(x+1);
    fr(i,0,x)s[x] =0;
    ll cont = 1;
    ll tmp = 0;
	///ir por los estados posibles
    while(x-cont > cont){
        ///guardar el xor de los estados 
        ///si un estado crea varios guardar la xor-suma de estos
        s[comp(x-cont)^comp(cont)] = 1;
        ///encontrar el mex
        while(s[tmp])tmp++;
        cont++;
    }
    
    return spg[x] = tmp;
}