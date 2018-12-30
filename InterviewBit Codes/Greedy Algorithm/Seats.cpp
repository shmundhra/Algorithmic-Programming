// https://www.interviewbit.com/problems/seats/

int Solution::seats(string A) {
    
    long long n = A.size() ; 
    
    long long num = 0 ; for ( char c : A ) if ( c == 'x' ) num++ ; 
    
    long long ans = 0 ;
    
    long long pref = 0 ; 
        for ( long long i = 0 ; pref <= num/2 and i < n ; i++ )
    {
        if ( A[i] == 'x')
        {
            pref++ ; 
        }
        else
        {
            ans = ( ans + pref ) %10000003 ; 
        }
    }
    
    
    long long suff = 0 ; 
    for ( long long j = n-1 ; suff <= (num-1)/2 and j > -1 ; j-- )
    {
        if ( A[j] == 'x')
        {
            suff++ ; 
        }
        else
        {
            ans = ( ans + suff ) %10000003 ; 
        }
    }
    
    return (int)ans ;
    
}
