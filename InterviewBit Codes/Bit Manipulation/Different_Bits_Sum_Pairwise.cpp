// https://www.interviewbit.com/problems/different-bits-sum-pairwise/

#define MOD 1000000007
int Solution::cntBits(vector<int> &A) {
    
    long long ans = 0 ; 
    
    for ( int i = 0 ; i < 32 ; i++ )
    {   
        long set = 0  ; 
        long fre = 0 ; 
        for ( int j = 0 ; j < A.size() ; j++ )
        {
            if ( ((A[j]>>i) & 1) )
            {
                set++ ; 
            }
            else
            {
                fre++ ;
            }
        }
        ans += (set * fre)%MOD ;
        ans %= MOD ; 
       
    }
    return (int)((ans+ans)%MOD) ; 
}
