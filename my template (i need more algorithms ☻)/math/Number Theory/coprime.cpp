/*

	. if n prime cop(n) = n-1
	
	. x^cop(n) mod n = 1

	. x^(n-1) mod n = 1

	. x^y mod n = x^(y mod (n-1)) mod n

	. x*invmod(x) mod n = 1

	. invmod(x) = x^(cop(n)-1)

    .sum of all gcd(x,y) 1<=x<=n  1<=y<=n
        fr(i,1,n)ta[i] = ta[i-1]+phi[i];
        fr(i,1,n)sum += i*ta[n/i];

    
*/

ll cnt=0;
vector<pair<ll,ll>>g;
bool np[10000005];
ll phi[10000005];
ll mob[10000005];
vector<ll>primo;

void criba(){
    ll x = 10000000;
    mob[1] = 1;
    fr(i,2,10000000){
        if(!np[i]){
            primo.pb(i);
            phi[i] = i-1;
            mob[i] = -1;
        }
        fr(j,0,primo.size()-1){
            if(i*primo[j]>x)break;
            np[i*primo[j]] = 1;
            if(i%primo[j]==0){
                phi[i*primo[j]] = phi[i] * primo[j];
                mob[i*primo[j]] = 0;
                break;
            } else {
                phi[i*primo[j]] = phi[i] * phi[primo[j]];
                mob[i*primo[j]] = mob[i] * mob[primo[j]];
            }
        }
    }
}
///descompose the number in prime
void div_n(ll num){
    g.clear();
    rep(v,primo){
        if(v*v > num)break;
        if(num%v==0)g.push_back({v,0});
        int ta = g.size();
        while(num%v==0){
            g[ta-1].second++;
            num/=v;
        }
    }
    if(num>1)g.push_back({num,1});
}

ll pot(ll y,ll x){
    if(y==0)return 1;
    if(y&1)return pot(y-1,x)*x;
    ll mid = pot((y>>1),x);
    return mid*mid;
}

///coprime number less than x
ll cop_less(ll x){
    div_n(x);
    cnt=1;
    rep(v,g)
        cnt*= pot(v.second-1,v.first)* (v.first-1);
    return cnt;
}

