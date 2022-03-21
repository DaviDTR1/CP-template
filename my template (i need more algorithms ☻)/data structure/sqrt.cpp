struct SQRT_DES{
    ll tsq[5005];
    ll leng;
    
    void build(ll x){
        leng = sqrt(x+0.0)+1;
        fr(i,0,x-1){
            tsq[i/leng] += ar[i+1];
        } 
    }
    ll query(ll l,ll r){
        ll res = 0;
        ll cl = (l/leng), cr = (r/leng);
        if(cl==cr){
            fr(i,l,r){
                res+=ar[i+1];
            }
            return res;
        }
        fr(i,l,(cl+1)*leng-1)
            res+=ar[i+1];
        fr(i,cl+1,cr-1)
            res+=tsq[i];
        fr(i,cr*leng,r){
            res+=ar[i+1];
        }
        return res;
    }

}sqrt_d;