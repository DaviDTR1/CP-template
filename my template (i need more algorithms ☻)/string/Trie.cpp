struct Trie{
    ll words,prefix;
    Trie* edges[30];
}*root = new Trie();

Trie* create(){
    Trie* tmp = new Trie();
    tmp->words=0;
    tmp->prefix=0;
    mem(tmp->edges,NULL);
    return tmp;
}

void add(Trie *s, string &a){
    rep(v, a){
        if(s->edges[v-'a']==NULL){
            s->edges[v-'a'] = create();
        } s = s->edges[v-'a'];
        s->prefix++;
    }
    s->words++;
}
ll countWords(Trie *s, string &a){
    rep(v, a){
        if(s->edges[v-'a']==NULL)
            return 0;
        s = s->edges[v-'a'];
    }
    return s->words;
}
ll countPrefix(Trie *s, string &a){
    rep(v, a){
        if(s->edges[v-'a']==NULL)
            return 0;
        s = s->edges[v-'a'];
    }
    return s->prefix;
}