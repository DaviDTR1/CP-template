/// first number a
/// last number b
/// numbers n
///sum of all x x1==a, xn == b  and x2-x1 = x3-x2

void sum(int a,int b){
    return ((n)*(a+b))>>1;
}

///sum of all x^2 1<= x <= n

void sum2(b){
    return ((n*(n+1)) * ((n<<1)+1))/6;
}

///sum of geometric progression with constant 2
/// S = a + ak + a(k^2) + ... + b
/// kS = ak + a(k^2) + a(k^3) + ... bk
/// kS - S = bk - a
/// S(k-1) = bk - a

void sum3(int a,int b,int k){
    return (b*k-a)/(k-1);
}


///harmonic progression
/// 1/1 + 1/2 + 1/3 .. 1/n <= log2(n);


///sum first n odd = N^2
///sum first n even = N^2 + N

///num tetraedic n*(n+1)*(n+2)/6

///Iterate all d|n
for(ll i = 1,d; i<= n; i=d+1){
    d = n/(n/i);
}