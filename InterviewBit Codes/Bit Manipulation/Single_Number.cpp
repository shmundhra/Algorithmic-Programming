// https://www.interviewbit.com/problems/single-number/

long long xor2 ( long long a , long long b )
{
    long long ans = 0 ; 
    
    for ( int i = 0 ; i < 32 ; i++ )
    {   
        long long fact = (long long) pow(2,i) ; 
        long long x = a / fact ; 
        long long y = b / fact ; 
        
        long long z = ( (x % 2) + (y % 2) ) %2 ;
        
        ans = ans + z*fact ; 
    }
    
    return ans ; 
}
int Solution::singleNumber(const vector<int> &A) {
    
    long long ans = 0 ; 
    for ( int i = 0 ; i < A.size() ; i++ ) 
    {
        ans = xor2( ans , A[i] ) ; 
    }
    return ans ; 
}