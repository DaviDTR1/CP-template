///Aho Corasick
struct vertex{
    ll next[K];
    ll suffix = 0;
    bool leaf = 0;
    vertex(){
        fill(begin(next), end(next),-1);
    }
};
vector<vertex> trie(1);
vi order;
vi sol;
vi nod;

void add_string(string const& s,ll id){
    ll v = 0;
    rep(u, s){
        int c = u-'A';
        if(trie[v].next[c] == -1){
            trie[v].next[c] = trie.size();
            trie.emplace_back();
            sol.pb(0);
        }
        v = trie[v].next[c];
    }
    trie[v].leaf = 1;
    nod[id] = v;

}

void buildAHO(){
    order.clear();
    ll v = 0;
    queue<ll>qp;
    fr(i,0,K-1){
        if(trie[v].next[i]!=-1){
            trie[v].suffix = v;
            qp.push(trie[v].next[i]);
        } else{
            trie[v].next[i] = v;
        }
    }
    while(!qp.empty()){
        v = qp.front();
        qp.pop();
        order.pb(v);
        fr(i,0,K-1){
            ll u = trie[v].next[i];
            if(u != -1){
                trie[u].suffix = trie[trie[v].suffix].next[i];
                qp.push(u);
            } else{
                trie[v].next[i] = trie[trie[v].suffix].next[i];
            }
        }

    }
}
///count the number of ways to create the string a[0:pos] with a set of words
void count_of_match(string &a){
    ll v = 0;
    ll pos = 0;
    rep(u, a){
        pos++;
        ll c = u-'a';
        v = trie[v].next[c];
        
        if(trie[v].leaf){
            dp[pos] += dp[pos- words[trie[v].leaf].size()];
            dp[pos]%=mod;
        }
        ll x = trie[v].near_leaf;
        while(x!=0){
            dp[pos] += dp[pos - words[trie[x].leaf].size()];
            dp[pos]%=mod;
            x = trie[x].near_leaf;
        }
    }
}

///move through the text and count the number of times I land on each position
void move(string &a){
    ll v = 0;
    rep(u, a){
        ll c = u-'A';
        v = trie[v].next[c];
        sol[v]++;
    }
    ll ta = order.size();
    for(ll i = ta-1; i>=0;i--){
        v = order[i];
        sol[trie[v].suffix] += sol[v];
    }
}
