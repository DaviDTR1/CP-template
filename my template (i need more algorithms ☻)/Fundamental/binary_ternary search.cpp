struct b_s{

    auto good(double mid){
        ///verify if m is good
        ll sol = 0;
        fr(i,1,n){
            sol += ar[i]/mid;
        }
        return sol >= k;
    }
    /// to real number
    ll bin_sr1(double l, double r){
        fr(i,1,100){
            double mid = (l+r)/2;
            if(good(mid))l = mid;
            else r = mid;
        }
        return l;
    }
    /// only for secuence like 1 1 1 1 1 0 0 0 0 , 1 are good and 0 bad
    ll bin_sr2(ll l,ll r){
        ll res = l-1;
        int p = 31 - __builtin_clz(r);
        for(int i = p; i>= 0;i--){
            //if(res + (1<<i) > r)continue;
            //if(good())res += (1<<i);
        }
        return res;
    }
    ///every monotony sequence
    ll bin_sr3(ll l,ll r){

        while(r > l+1){
            ll mid = (l+r)>>1;
            if(good(mid))r = mid;
            else l = mid;
        }
        return r;
    }
    ///in some problems is necesary to use real numbers
    ll ter_sr(ll l, ll r){
        while(r>l+3){
            ll m1 = l + (r-l)/3;
            ll m2 = r - (r-l)/3;
            if(good(m1) < good(m2))l = m1;
            else r = m2;
        }
        ///verify the answer from l to r
        return l;
    }

}bs;