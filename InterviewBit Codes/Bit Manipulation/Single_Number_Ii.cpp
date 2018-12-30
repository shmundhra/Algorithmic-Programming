// https://www.interviewbit.com/problems/single-number-ii/

long long xor3 ( long long a , long long b )
{
    long long ans = 0 ;
    
    for ( int i = 0 ; i < 20 ; i++ )
    {   
        long long fact = (long long) pow(3,i) ; 
        long long x = a / fact ; 
        long long y = b / fact ; 
        
        long long z = ( (x % 3) + (y % 3) ) %3 ;
        
        ans = ans + z*fact ; 
    }
    
    return ans ; 
}
int Solution::singleNumber(const vector<int> &A) {
    
    long long ans = 0 ; 
    /*
    for ( int i = 0 ; i < A.size() ; i++ ) 
    {
        ans = xor3( ans , A[i] ) ; 
    }
    */
   
   for ( int i = 0 ; i < 32 ; i++ )
   {    
       int sum = 0 ; 
       for ( auto v : A )
       {
           sum += (v>>i)&1 ; 
       }
       sum %= 3 ; 
       ans += ((bool)sum)<<i ; 
   }
   return ans ;
}
