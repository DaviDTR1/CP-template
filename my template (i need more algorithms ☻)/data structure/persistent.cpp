#include<bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
*/
using namespace std;
/*
typedef tree<int,null_type, less<int>,rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;
*/
#define pb push_back
#define ll long long
#define x1 first
#define y1 second
#define frb(i,a,b) for(ll (i)=(a);(i) <= (b); (i)+=(i)&-(i))
#define rfrb(i,a) for(ll (i)=(a);(i) > 0;(i)-=(i)&-(i))
#define fr(i,a,b) for(ll (i) = (a); (i) <= (b); (i)++)
#define rep(i,c) for(auto (i) : (c))
#define mini(a,b) (((a) < (b)) ? (a) : (b))
#define maxi(a,b) (((a) > (b)) ? (a) : (b))
#define par pair<ll,ll>
#define vp vector<par>
#define vi vector<ll>
#define dq deque<ll>
#define mem(i,j) memset((i),(j),sizeof (i))
//indexed_set s; 
///always see the properties of the problems
///siempre poner ("\n" cout.flush) como endl
///compare doubles a,b fabs(a-b)<eps
///----------------------------------------------------------------------------

const ll mod = 1e9+7;
const ll INF = 1e18;
int n,t;
int L[300005 * 25],R[300005 * 25], st[300005 * 25],root[300005];
int id;
int ar[300005];
map<int,int>as;
struct trio{
    int year, pos, seg;
};
vector<trio>quer;

void upd(int act, int ant, int l,int r,int k){
    st[act] = st[ant]+1;
    if(l==r){
        return;
    }
    int m = (l+r)>>1;
    if(m>=k){
        L[act] = ++id;
        R[act] = R[ant];
        upd(L[act], L[ant], l, m, k);
    } else{
        R[act] = ++id;
        L[act] = L[ant];
        upd(R[act], R[ant], m+1, r, k);
    }
}

int query(int act, int ant, int l, int r, int k){
	if(l == r)
		return st[act] - st[ant];
	int m = (l+r)>>1;
	int count = st[L[act]] - st[L[ant]];
	if(m >= k)
		return query(L[act], L[ant], l, m, k);
	return count + query(R[act], R[ant], m+1, r, k);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout.setf(ios::fixed);cout.precision(0);
    ///freopen("a.in","r",stdin);
    ///freopen("a.out","w",stdout);
    cin>>n>>t;
    int a,b,c;
    fr(i,1,n){
        cin>>ar[i];
        as[ar[i]];
    }
    fr(i,1,t){
        cin>>a>>b>>c;
        quer.push_back({a,b,c});
        as[b];
    }
    int maxm = 0;
    rep(i, as){
        maxm++;
        as[i.first] = maxm;
    }
    fr(i,1,n){
        root[i] = ++id;
        upd(root[i], root[i-1], 1, maxm, as[ar[i]]);
    }
    rep(i, quer){
        int res = 0;
        if(ar[i.year] < i.pos)
            res = st[root[i.year+i.seg]] - st[root[i.year]] - query(root[i.year+i.seg], root[i.year], 1, maxm, as[i.pos]-1);
        cout<<res<<"\n";
    }
    return 0;
}