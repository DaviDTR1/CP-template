/*
	Inclusion-Exlusuion

	. T = {X1 U X2 U X3 U ... U XN}

	. |A U B| = |A| + |B| - |A ∩ B|

	. |A U B U C| = |A|+|B|+|C| - |A ∩ C| - |A ∩ B| - |B ∩ C| + |A ∩ B ∩ C|

	. S = |XJ ∩ XJ+1 ∩ ... ∩ XI| if I-J+1 even T -= S
	
	. S = |XJ ∩ XJ+1 ∩ ... ∩ XI| if I-J+1 odd T += S
	
	.Counting Derangements, derangements permutiations of S = {x1,x2,x3,x4,x5,...,xn} where no elements remains in its original place
		T = !N - |X1 ∩ X2 ∩ X3 ∩ ... ∩ XN| , Xk  = permutations than contain element K in position K


	Burnside’s Lemma

	. Burnside’s lemma can be used to count the number of distinct combinations so that symmetric combinations are counted only once

	 Example:he number of necklaces of n pearls, where each pearl has m possible colors  Two necklaces are symmetric if they are simi-
		lar after rotating them
	
	 Solution: T = (1/n)∑m^gcd(k,n) 1<=k<=n  or  T = (1/n)∑ɸ(n/d)*m^d   d|n


	Cayley’s Formula
	
	.Cayley’sformula states that there are a total of (n^n−2) distinct labeled trees of n nodes
*/