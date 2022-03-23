/*
    . Cat(n) = number of valid parenthesis expressions with n rigth parentheses and n left parentheses
    
    . Cat(n) = number of binary trees of n nodes and number of rooted trees of (n+1) nodes
*/

const ll mod = 1e9+7;
ll comb[5005][5005];
ll cat[7005];
void build_co(ll num){
    fr(i,0,num)
        comb[i][0] = 1;
    fr(i,1,num){
        fr(j,1,i){
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%mod;
        }
    }
}
void build_ca(ll num){
    cat[0]=1;
    fr(i,1,num)cat[i] = 0;
    fr(i,1,num){
        fr(j,0,i-1){
            cat[i] += (cat[j]*cat[i-j-1])%mod;
            cat[i] %= mod;
        }
    }
}
ll pot(ll y,ll x){
    if(y==0)return 1;
    if(y&1)return (pot(y-1,x)*x)%mod;
    ll mid = pot((y>>1),x);
    return (mid*mid)%mod;
}
ll c_n1(ll n){
    return (comb[n<<1][n] * pot(mod-2,n+1))%mod;
}