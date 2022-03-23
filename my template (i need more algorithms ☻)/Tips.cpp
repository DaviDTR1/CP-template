/*
1.
	call negative indices
	const ll tm = 1e5;
	ll _aq[tm*2+5];
	ll* aq = _aq+tm;
2.
	forms to count C(i,k) + C(i,k*2) + C(i,k*3) + ... C(i,k*x)  (k*x <= i)
	dp[i] = dp[i-1] + dp[i-k];
3. 
	the probability of simultaneous events is the product of their probabilities
4. 
	number of segment in a array of length n = n*(n+1)/2
5. 
	for A <= B <= C <= D
	max(A+D, B+C) <= max(A+C, B+D)
	min(A+C, B+D) <= min(A+D, B+C)
6. 
	find how different number are in an interval
	create an array with for each number have the position of the last equal number

*/