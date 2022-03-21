/* 

    . number of way to pick k numbers in a set of n number  comb(i,j)

    . comb(i,j) = comb(i-1,j) + comb(i-1,j-1)

    . comb(n,k) = n!/(!k * !(n-k))

    . comb(n,0) + comb(n,1) + .... comb(n,n-1) + comb(n,n) = 2^n

    . (a+b)^n = comb(n,0)*(a^n)*(b^0) + comb(n,1)*(a^(n-1))*(b^1) + .... + comb(n,n-1)*(a^1)*(b^(n-1)) + comb(n,n)*(a^0)*(b^n)

    . comb(,. {k1,k2,k3,...,km}) = !n / (!k1 * !k2 * !k3 * ... * !km)

    . number of way to set k balls in a set of n box  and each box can contain a multiple balls comb(n+k-1,k)

    . number of way to set k balls in a set of n box  and no two adjacent boxes may both contain a ball comb((n-k+1),(n-2k+1))
*/

struct bin_coef{
    const ll mod = 1e9+7;
    ll comb[5005][5005];
    ll fact[200005];

    par fib(ll x){
        if(x==0)return {0,1}; 
        auto p = fib(x>>1);
        ll c = p.first * (2*p.first + p.second) %mod;
        ll d = p.first * p.first + p.second * p.second %mod;
        if(n&1)return {d,c+d};
        return {c,d};
    }

    void build_p(ll num){
        fr(i,0,num)
            comb[i][0] = 1;
        fr(i,1,num){
            fr(j,1,i){
                comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%mod;
            }
        }
    }
    void build_f(ll num){
        fact[0] = 1;
        fr(i,1,num)fact[i] = (fact[i-1]*i)%mod;
    }

    ll pot(ll y,ll x){
        if(y==0)return 1;
        if(y&1)return (pot(y-1,x)*x)%mod;
        ll mid = pot((y>>1),x);
        return (mid*mid)%mod;
    }

    ll n_k1(ll a,ll b){
        ll res;
        res = ((fact[b]*pot(mod-2,fact[a]))%mod*pot(mod-2,fact[b-a]))%mod;
        return res;
    }
}bf;