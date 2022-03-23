/*
	. p|a and p|b  ,  p|(a+b)
	. p|a and p|(a+b)  ,  p|b

	. S(n) = (a^1 + a^2 + ... + a^n)     S(2n) = S(n) * (1 + a^n)    S(2n+1) = S(2n) + (a^(2n))*a
	
	.Cantidad de divisores de un n = (x < sqrt(n))

*/

///suma de los divisores de un numero <= 10^7 en 10^7*log(10^7) < 2 segundos
for(ll i=1; i <=10000000;i++){
   	for(ll j = i; j<= 10000000;j+=i){np[j] += i;}
    	if(np[i]<=10000000){if(br[np[i]]==0)br[np[i]] = i;}
}

/*
	.The Chicken McNugget states that for any two relatively prime positive integers m,n,
	 the greatest integer that cannot be written in the form am + bn for nonnegative integers a, b is mn-m-n. 
	. All multiples of gcd(m, n) greater than lcm(m, n)-m-n 
	are representable in the form am+bn for some positive integers a, b.

	.The secuence (1 + x + x^2 + x^3 + x^4 + ... + x^n) = (x^(n+1) - 1 ) / (x-1)


*/