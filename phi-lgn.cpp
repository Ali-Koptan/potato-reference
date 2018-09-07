long long phi(long long n){
	long long result  = n;
    for (long long p = 2; p * p <= n; p++){
        if (n % p == 0){
            while (!(n%p))
                n/=p;
            result*=(1.0-(1.0/(double)p));
        }
    }
    if (n > 1)
        result*=(1.0-(1.0/(double)n));
 
    return (long long)result;
}