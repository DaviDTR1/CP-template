/*
    . ax + by = gcd(a,b)
    
    . lcm(a,b) = a*b/gcd(a,b) 

    Diophantine Equations is  a equation of the form
    . ax + by = c
    we can efficiently solve a Diophantine Equations by using  extended Euclid’s
    algorithm if c|gcd(a,b)
    We can form an infinite solutions if we know one solution 
    using 

    . x'1 = x +k*b/gcd(a,b) , y'1 = y - k*a/gcd(a,b)  
    
    k is any integer
*/
struct euclid{
    ll x,y;

    ll shift_sol(ll &x, ll &y, ll a,ll b,ll cnt){
        x += cnt*b;
        y -= cnt*a;
    }

    ll gcd(ll a,ll b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    ll ext_gcd(ll a,ll b){
        if(b==0){x = 1, y = 0;return a;}
        ll x2,y2,re;
        re = ext_gcd(b,a%b);
        x2 = y;
        y2 = x-(a/b)*y;
        x = x2;
        y = y2;
        return re;
    }
    ll lcm(ll a,ll b){
        return a*b/gcd(a,b);
    }
    bool fsol_interval(ll minx, ll maxx, ll miny, ll maxy, ll &x, ll &y,ll a,ll b,ll c){
        ll z = ext_gcd(a,b);
        if(c%z)return 0;
        x *= c/z;
        y *= c/z;
        a /= z;
        b /= z;
        ll sga = (a<0 ? -1 : 1);
        ll sgb = (b<0 ? -1 : 1);
        shift_sol(x,y,a,b,(minx-x)/b);
            if(x<minx)shift_sol(x,y,a,b,sgb);
            if(x>maxx){
                return 0;
            }
        ll l1 = x;
        shift_sol(x,y,a,b,(maxx-x)/b);
            if(x>maxx)shift_sol(x,y,a,b,-sgb);
        ll r1 = x;
        shift_sol(x,y,a,b,-(miny-y)/a);
            if(y<miny)shift_sol(x,y,a,b,-sga);
            if(y>maxy){
                return 0;
            }
        ll l2 = x;
        shift_sol(x,y,a,b,-(maxy-y)/a);
            if(y>maxy)shift_sol(x,y,a,b,sga);
        ll r2 = x;
        if(l2>r2)swap(l2,r2);
        l1 = max(l1,l2);
        r1 = min(r1,r2);
        if(l1>r1)return 0;
        return 1;
        //cant sol
        //return (r1-l1)/abs(b)+1;
    }

}ec;