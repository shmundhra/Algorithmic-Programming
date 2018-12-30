// https://www.interviewbit.com/problems/divide-integers/

long long abso ( long long A ){  return -A ; }

int Solution::divide(int A, int B) {
    
    if ( B == 1  )  return A ; 
    if ( B == -1 ) { if ( A == INT_MIN ) return INT_MAX ; return -A ; }
    
    long long Div = abso((long long)A) ;
    long long divi ; long long power ; long long quot = 0 ; 
    long long b = abso((long long)B) ; 
    
    while ( Div >= b )
    {
        divi  = b  ;
        power = -1 ; 
        while ( Div >= divi )
        {   
            divi<<=1 ; power++ ; 
        }
        divi>>=1    ; 
        Div -= divi ; 
        quot += (1<<power) ; 
    }
    
    if ( (A<0) ^ (B<0) ) return  ((-quot<INT_MIN)?INT_MIN:-quot ) ; 
    else return ((quot>INT_MAX)?INT_MAX:quot ) ; 
    
}
