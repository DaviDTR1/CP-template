ll n;
vi g;

    ll res = 0,sum = 0;
    bool good(){
        ///Condition
        return 0;
    }
    /// number of (l,r) with sum = {ar[l] + ... + ar[r]} <= s
    ll comp(ll k,ll s){
        ll l = 1;
        res = 0,sum = 0;
        fr(r,1,k){
            sum += g[r];
            while(l <= k && sum > s)
                sum -= g[l++];
            if(sum <= s)
                res += r-l+1;
        }
        return res;
    }

    void add(ll x){
        /// add x to the segment
    }
    void remv(ll x){
        /// remove x of the segment
    }
    ll comp2(ll k,ll s){
        ll l = 1;
        fr(r,1,k){
            add(g[r]);
            while(l <= k && !good())
                remv(g[l++]);
            ///Update result
        }
        return res;
    }