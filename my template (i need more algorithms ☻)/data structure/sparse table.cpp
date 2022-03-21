struct Sp_Ta{
    ll spt[30][1000005];
    void build(ll x){
        ll ta = 31-__builtin_clz(x);
        fr(i,1,x)spt[0][i] = cor[i].second;
        fr(k,1,ta){
            fr(i,1,x-(1<<k)+1){
                spt[k][i] = max(spt[k-1][i],spt[k-1][i+(1<<(k-1))-1]);
            }
        }
    }
    ll query(ll x, ll y){
        ll ta = 31 - __builtin_clz((y-x+1));
        return max(spt[ta][x], spt[ta][y-(1<<(ta))+1]);
    }
}spta;