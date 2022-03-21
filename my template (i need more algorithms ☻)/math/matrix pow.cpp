struct MatP{
    vector<vector<ll> > root;
    ll ta = 1, tb = 1, tc =  1;
    void build(){
        vi g;
        fr(i,1,n){
            g.clear();
            fr(j,1,m){
                g.pb(ar[i][j]);
            }
            root.pb(g);
        }
    }

    void mt_pow(vector<vector<ll> > &mat, ll y){
        if(y==0 || y==1)return;
        if(y&1){
            mt_pow(mat,y-1);
            vector<vector<ll> > tmp = root;
            fr(i,0,ta){
                fr(j,0,tb){
                    tmp[i][j] = 0;
                    fr(k,0,tc){
                        tmp[i][j] += mat[i][k] * root[k][j];
                        tmp[i][j] %= mod;
                    }
                }
            }
            mat = tmp;
            return;
        }
        mt_pow(mat,y>>1);
        vector<vector<ll> > tmp = root;
        fr(i,0,ta){
            fr(j,0,tb){
                tmp[i][j] = 0;
                fr(k,0,tc){
                     tmp[i][j] += mat[i][k] * mat[k][j];
                     tmp[i][j] %= mod;
                }
             }
        }
        mat = tmp;
    }  
}mtp;