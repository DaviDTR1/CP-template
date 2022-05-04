vi lmost(1000005);
vi rmost(1000005);

void build_interval(vi &ar,ll tam){
    ar[0] = ar[n+1] = 0;
    stack<ll>left,right;
    left.push(0);
    right.push(n+1);
    ///find position that ar[i] is leftmost minimun
    fr(i,1,n){
        ll x = left.top();
        while(ar[x] > ar[i]){
            left.pop();
            x = left.top();
        }
        lmost[i] = x+1;
        if(ar[x]==ar[i])lmost[i] = lmost[x];
        left.push(i);
    }
    ///find position that ar[i] is rightmost minimun
    for(ll i=n;i>0;i--){
        ll x = right.top();
        while(ar[x] > ar[i]){
            right.pop();
            x = right.top();
        }
        rmost[i] = x-1;
        right.push(i);
    }
}