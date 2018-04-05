//for combinatorics problems.
 
const int mod = 1e9+7;
const int r = 1e5+7;
long long fastp(long long a, long long b)
{
    if (b==0)
        return 1;
    if (b%2)
        return (fastp((a*a)%mod, b/2)*a)%mod;
    return fastp((a*a)%mod, b/2)%mod;
}
long long fact[r];
void gfact()
{
    fact[0]=1;
    fact[1]=1;
    for (long long i=2; i<r; i++)
        fact[i] = (i*fact[i-1])%mod;
}
long long nCr(int n, int r)
{
    long long t = fact[n];
    long long b = fact[n-r] * fact[r];
    b%=mod;
    t=(t*fastp(b, mod-2))%mod;
    return t;
}
