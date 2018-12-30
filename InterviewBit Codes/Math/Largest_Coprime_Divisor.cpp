// https://www.interviewbit.com/problems/largest-coprime-divisor/

bool coprime( int a , int b )
{
    //cout<<a<<"#"<<b<<"#" ; 
    while ( b )
    {
        int temp = a%b ; 
        a = b ; 
        b = temp ; 
    }
    //cout<<a<<"#" ; 
    if ( a == 1 ) return true  ; 
    else          return false ; 
    
}
int Solution::cpFact(int A, int B) {
    
    int i ; 
    int maxi = INT_MIN ; 
    for ( i = 1 ; i*i <= A ; i++ )
    {
        if ( A%i == 0 )
        {
             if ( coprime ( max(B,A/i) , min(B,A/i) )  )
                maxi = max ( A/i , maxi ) ;
             
             if ( coprime ( max(B,i) , min(B,i) )  )
                maxi = max ( i , maxi ) ;
             
             if ( B%i==0 )
                A/=i ; 
        }
    }
    return maxi ; 
   
}
