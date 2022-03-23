/*
    suffix array with longest common preffix
    # < $
*/
int n,t;
int tlcp[25][400005];
string s;

void count_sort(vi &p, vi &c){
    vi n_p(n);
    vi cnt(n);
    vi pos(n);
    rep(x, c){
        cnt[x]++;
    }
    pos[0] = 0;
    fr(i,1,n-1){
        pos[i] = pos[i-1]+cnt[i-1];
    }
    rep(x, p){
        int y = c[x];
        n_p[pos[y]] = x;
        pos[y]++;
    }
    p = n_p;
}

void build(){
    cin>>s;
    s+='$';
    n = s.size();
    vector<int>p(n), c(n);
    {
        vector<pair<char,int>>ar(n);
        fr(i,0,n-1){
            ar[i] = {s[i],i};
        }
        sort(ar.begin(),ar.end());
        fr(i,0,n-1){
            p[i] = ar[i].second;
        }
        c[p[0]] = 0;
        fr(i,1,n-1){
            if(ar[i].first != ar[i-1].first){
                c[p[i]] = c[p[i-1]] + 1;
            }
            else c[p[i]] = c[p[i-1]];
        }
    }
    int k = 0;
    while((1<<k) < n){
        fr(i,0,n-1){
            p[i] = (p[i] - (1<<k) + n)%n;
        }
        count_sort(p, c);
        vi n_c(n);
        n_c[p[0]] = 0;
        fr(i,1,n-1){
            par now = {c[p[i]], c[(p[i] + (1<<k))%n]};
            par rev = {c[p[i-1]], c[(p[i-1] + (1<<k))%n]};
            if(now != rev){
                n_c[p[i]] = n_c[p[i-1]] + 1;
            }
            else n_c[p[i]] = n_c[p[i-1]];
        }
        c = n_c;
        k++;
    }
    vi lcp(n);
    k = 0;
    fr(i,0,n-2){
        int p1 = c[i];
        int j = p[p1 - 1];
        while(s[i+k] == s[j+k])k++;
        lcp[p1] = k;
        k = max(k-1,0);
    }
    vi posi(n);
    k = 31-__builtin_clz(n);
    fr(i,1,n-1){tlcp[0][i] = lcp[i];posi[p[i]+1] = i;}
    fr(x,1,k)
         fr(i,1,n-(1<<x))
            tlcp[x][i] = mini(tlcp[x-1][i], tlcp[x-1][i+(1<<(x-1))]);

}