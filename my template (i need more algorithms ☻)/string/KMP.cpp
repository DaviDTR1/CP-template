///KMP
vi pref;

ll kmp(string t,string s){
    string a,b;
    a = s + "#" + t;
    ll ta = a.size();
    vi cnt(ta);
    pref.resize(s.size());
    ll solt = s.size();
    cnt[0]=0;
    ///cnt[i] store the largest prefix that is suffix in i
    fr(i,1,ta-1){
        ll j = cnt[i-1];
        while(j > 0 && a[i]!=a[j]){
            j = cnt[j-1];
        }
        if(a[i]==a[j])j++;
        cnt[i] = j;
    }
    ///count the number of ocurrence of each prefix of S in T
    pref[0] = 1;
    fr(i,s.size()+1,ta-1){
        if(cnt[i]!=0)
            pref[cnt[i]-1]++;
    }
    for(ll i=s.size()-1; i > 0;i--)
        if(cnt[i-1]!=0)
            pref[cnt[i-1]-1] += pref[i];
    //Find less compressed string of S
    ll lessc = s.size()-cnt[s.size()-1];
    if((s.size())%lessc!=0)lessc = s.size();

    return pref[solt];
}
