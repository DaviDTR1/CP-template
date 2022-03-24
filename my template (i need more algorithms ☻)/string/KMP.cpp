///KMP
vi pref;
vi solid;

ll kmp(string s,string t){
    string a;
    a = s + '#' + t;
    ll ta = a.size();
    vi cnt(ta);
    pref.resize(s.size()+1);
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
    fr(i,s.size()+1,ta-1){
        pref[cnt[i]]++;
    }
    for(ll i=s.size()-1; i > 0;i--)
            pref[cnt[i-1]] += pref[i];
    fr(i,1,s.size()-1)pref[i]++;
    ///length of preffix of S that are suffix in T
    ta = s.size(); 
    solid.pb(ta);
    ta--;
    while(cnt[ta]){
        solid.pb(cnt[ta]);
        ta = cnt[ta]-1;
    }
    //Find less compressed string of S
    ll lessc = s.size()-cnt[s.size()-1];
    if((s.size())%lessc!=0)lessc = s.size();

}
