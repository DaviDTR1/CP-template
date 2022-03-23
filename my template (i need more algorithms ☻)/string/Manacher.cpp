void build(string &a){
    ll ta = a.size();
    d1.resize(ta);
    d2.resize(ta);
    for(ll i = 0, l = 0, r = -1; i<ta;i++){
        ll k = (i>r) ? 1LL : min(d1[l+r-i], r-i+1);
        while(0 <= i-k && i+k < n && a[i-k]==a[i+k])
            k++;
        d1[i] = k--;
        if(i + k > r){
            l = i-k;
            r = i+k;
        }
    }
    for(ll i = 0, l = 0, r = -1; i<ta;i++){
        ll k = (i>r) ? 0LL : min(d2[l+r-i+1], r-i+1);
        while(0 <= i-k-1 && i+k < n && a[i-k-1]==a[i+k])
            k++;
        d2[i] = k--;
        if(i+k > r){
            l = i-k-1;
            r = i+k;
        }
    }
}