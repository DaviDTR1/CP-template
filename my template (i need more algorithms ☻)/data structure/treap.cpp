
struct item {
    int key, prior, cnt;
	bool rev;
    item *l, *r;
    item (){l==NULL, r==NULL;}
	/// implicit prior(prior)
    item(int key): key(key), prior(rand()), l(NULL), r(NULL){};
};

typedef struct item * pitem;

pitem treap;

    int cnt(pitem t){
        return t ? t->cnt : 0;
    }
    void upd_cnt (pitem t){
        if(t) t->cnt = 1 + cnt(t->l) + cnt(t->r);
    }
	/*implicit
	void push(pitem it){
		if(it && it->rev){
			it->rev = false;
			swap(it->l, it->r);
			if(it->l)it->l->rev ^= true;
			if(it->r)it->r->rev ^= true;
		}
	}
	*/

    void split(pitem t, int key, pitem &l, pitem &r){
        if(!t){
            l=r=NULL;
            return ;
        }
		/*implicit
		push(t);
		ll cur_key = add + cnt(t->l);
        if(key <= cur_key){
            split(t->l, l, t->l, key, add), r = t;
        } else {
            split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
        }
		*/
        if(key < t->key){
            split(t->l, key, l, t->l), r = t;
        } else {
            split(t->r, key, t->r, r), l = t;
        }
        upd_cnt(t);
    }

 

    void merge(pitem & t, pitem l, pitem r){
		/* implicit
		push(l);
		push(r);
		*/
        if(!l && !r){
            t = NULL;
            return;
        }
        if(!l || !r)
            t = l ? l : r;
        else if(l->prior > r->prior){
            merge(l->r, l->r, r), t = l;
        } else {
            merge(r->l, l, r->l), t = r;
        } 
        upd_cnt(t);
    }
	/*implicit
	void reverse (pitem t, int l, int r) {
		pitem t1, t2, t3;
		split (t, t1, t2, l);
		split (t2, t2, t3, r-l+1);
		t2->rev ^= true;
		merge (t, t1, t2);
		merge (t, t, t3);
	}
	void output (pitem t) {
		if (!t)  return;
		push (t);
		output (t->l);
		printf ("%d ", t->value);
		output (t->r);
	}
	*/
	
	
	///regular
    void erase(pitem & t, int key){
        if(!t)return;
        if(t->key == key){
            pitem th = t;
            merge(t, t->l, t->r);
            delete th;
        } else {
            erase (key < t->key ? t->l : t->r, key);
        }
		upd_cnt(t);
    }
	   void insert(pitem & t, pitem it){
        if(!t) t = it;
        else if(it->prior > t->prior){
            split(t, it->key, it->l, it->r), t = it;
        } else {
            insert(it->key < t->key ? t->l : t->r, it);
        }
        upd_cnt(t);
    }

	int find_id_k(pitem &t, int val){
		if(cnt(t->l)+1 ==val)return t->key;
		else if(cnt(t->l) >= val ){
			return find_id_k(t->l, val);
		} else {
			return find_id_k(t->r, val-cnt(t->l)-1);
		}
	}

	int find_less(pitem t, int val, int soli){
		if(!t)return -1;
		if(t->key==val)
			return cnt(t->l)+1+soli;
		if(t->key > val)
			return find_less(t->l, val, soli);
		else return find_less(t->r, val, soli+cnt(t->l)+1);
	}