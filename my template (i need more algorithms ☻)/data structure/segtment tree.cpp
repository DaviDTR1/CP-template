struct S_T{
    ///for sum
        void propagate(ll lv,ll l,ll r,ll x){
            if(l!=r){
                lazy[lv<<1] = x;
                lazy[(lv<<1)+1] = x;
            }
            ///calc value in st[lv]

        }
        void build(ll lv,ll l,ll r){
            ll mid = (l+r)>>1;
            if(l==r){
                st[lv] = ar[l];
                return;
            }
            build(lv<<1,l,mid);
            build((lv<<1)+1,mid+1,r);
            st[lv] = st[lv<<1] + st[(lv<<1)+1];
        }
        void update(ll lv,ll l,ll r,ll id,ll x){
            ll mid = (l+r)>>1;
            if(l==r){
                st[lv] = x;
                return;
            }
            if(mid >= id)update(lv<<1,l,mid,id,x);
            else update((lv<<1)+1,mid+1,r,id,x);
            st[lv] = st[lv<<1] + st[(lv<<1)+1];
        }
        ll query(ll lv,ll l,ll r,ll x,ll y){
            ll mid = (l+r)>>1;
            if(l >= x && r <= y){
                return st[lv];
            }
            if(l > y || r < x){
                return 0;
            }
            return query(lv<<1,l,mid,x,y) + query((lv<<1)+1,mid+1,r,x,y);
        }
        ///min
        ll query1(ll lv,ll l,ll r,ll x,ll y){
            ll mid = (l+r)>>1;
            if(l >= x && r <= y){
                return st[lv];
            }
            if(l > y || r < x){
                return -1;
            }
            ll p1 = query1(lv<<1,l,mid,x,y);
            ll p2 = query1((lv<<1)+1,mid+1,r,x,y);
            if(p1==-1)return p2;
            if(p2==-1)return p1;
            return min(p1,p2);
        }
} s_t;

struct S_T{
    ///find maximun segment where id is the greater one
        void build(ll lv,ll l,ll r){
            ll mid = (l+r)>>1;
            if(l==r){
                st[lv] = ar[l];
                return;
            }
            build(lv<<1,l,mid);
            build((lv<<1)+1,mid+1,r);
            st[lv] = max(st[lv<<1] , st[(lv<<1)+1]);
        }
        ll query1(ll lv,ll l,ll r,ll x,ll y,ll id,ll p){
            ll mid = (l+r)>>1;
            if(l >= x && r <= y){
                if(l==r && ar[l]>=id && !p)return l+1;
                if(l==r && ar[l]>=id && p)return l-1;
                if(st[lv]< id && p)return n;
                if(st[lv]< id && !p)return 1;
                if(!p){
                    if(st[(lv<<1)+1] >= id)return query1((lv<<1)+1,mid+1,r,x,y,id,p);
                    else return query1(lv<<1,l,mid,x,y,id,p);
                }
                else{
                    if(st[lv<<1] >= id)return query1(lv<<1,l,mid,x,y,id,p);
                    else return query1((lv<<1)+1,mid+1,r,x,y,id,p);
                }
            }
            if(l > y || r < x){
                return -1;
            }
            ll p1 = query1(lv<<1,l,mid,x,y,id,p);
            ll p2 = query1((lv<<1)+1,mid+1,r,x,y,id,p);
            if(p1==-1)return p2;
            if(p2==-1)return p1;
            if(!p)return max(p1,p2);
            return min(p1,p2);
        }
} s_t;
