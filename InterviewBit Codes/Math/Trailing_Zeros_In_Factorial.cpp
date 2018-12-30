// https://www.interviewbit.com/problems/trailing-zeros-in-factorial/

typedef long long ll ; 

int Solution::trailingZeroes(int A) {
    
    /*int count = 0 ; 
    
    for ( int i = 5 ; i <= A ; i*=5 )
        count+= A/i ; 
        
    return count ; */
    
    ll low  = 0 ; 
    ll high = (int)( log(A)/log(5) ) ; 
    cout<<high ; 
    
    while ( low < high )
    {
        ll mid = low + ( high - low + 1) / 2 ; 
        
        ll fact = (ll) pow ( 5 , mid ) ;
        
        if ( A % fact == 0 )
        {
            low = mid ; 
        }
        else
        {
            high = mid-1 ; 
        }
    }
    return low ; 
}
