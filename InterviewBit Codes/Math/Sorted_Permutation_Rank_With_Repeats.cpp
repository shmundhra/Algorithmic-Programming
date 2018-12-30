// https://www.interviewbit.com/problems/sorted-permutation-rank-with-repeats/

#define MOD 1000003 
unsigned long long  modexp ( unsigned long long  base , unsigned long long  expo , unsigned long long  modulo )
{
    base = base % modulo ;
    unsigned long long  ans = 1 ;
    while ( expo )
    {
        if ( expo&1 )
            ans = (ans * base) % modulo ;

        expo >>= 1 ;
        base = (base*base)% modulo  ;

    }
    return ans ;
}

unsigned long long  fact ( unsigned long long  n )
{
    unsigned long long  ans = 1 ; 
    while(n) 
    {
        ans = ( (ans%MOD) * (n%MOD ) ) % MOD ; 
        n-- ; 
    }
    
    return (ans%MOD) ; 
}

int index ( char c ) 
{
    if ( isupper(c) )
    {
        return ( c - 'A' ) ; 
    }
    else
    {
        return ( c - 'a' + 26 ) ; 
    }
}

int Solution::findRank(string A) {
    
    if ( A.size() == 0 ) return 0 ; if ( A.size() == 1 ) return 1 ;
    
    vector < int > count ( 52 , 0 ) ; 
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        count[ index(A[i]) ] ++ ; 
    }
    
    
    unsigned long long  perm = 1 ; 
    for ( int i = 0 ; i < 52 ; i++ )
            perm  *= fact(count[i]) ;
         
            
    unsigned long long num = 1 ; 
    for ( int i = 0 ; i < A.size() ; i++ )
    {   
        //cout<<perm<<"##" ;
        for ( int j = 0 ; j < index( A[i] ) ; j++ )
        {
            if ( count[j] != 0 )
            {   
                //cout<<j<<"*" ; 
                unsigned long long ans ;
                ans =  ( count[j] % MOD * fact(A.size()-1 -i) % MOD ) % MOD ; 
                ans *= modexp( perm , MOD-2 , MOD ) ; 
                ans %= MOD ; 
                //cout<<ans<<"*" ; 
                num = (num + (ans)%MOD)%MOD ; 
            }
        }
        perm /= count[ index( A[i] ) ] ; 
        count[ index( A[i] ) ] -- ; 
        //cout<<num<<endl ; 
    }
    
    return num ; 
    
    
}
