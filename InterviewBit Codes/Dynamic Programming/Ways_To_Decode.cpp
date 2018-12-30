// https://www.interviewbit.com/problems/ways-to-decode/

bool check ( int i , string &s )
{   
    int x = 10*(s[i]-48) + (s[i+1]-48) ; 
    
    if ( s[i+2] == 48 ) return false ; 
    
    if ( x >= 11 and x <= 26 and x != 20 ) return true ; return false ; 
}


int Solution::numDecodings(string A) {
    
    int n = (int)A.size() ;
    
    for ( int i = 0 ; i < n ; i++ ) if ( !isdigit(A[i]) ) return 0 ;if ( A[0] == '0' ) return 0 ; 
    for ( int i = 1 ; i < n ; i++ ) if ( A[i] == '0' and !(A[i-1] == '1' or A[i-1] == '2'))  return 0 ; 
    
    if ( !n ) return 0 ; 
    if ( n == 1 ) return 1 ; 
    
    vector < int > dp ( n , 0 ) ; 
    
    dp[n-2] = dp[n-1] = 1 ; 
    if ( check(n-2,A) ) dp[n-2] ++ ; 
    
    for ( int i = n-3 ; i >= 0 ; i-- )
    {   
        dp[i] = dp[i+1] ; 
        if ( check(i,A) ) dp[i] += dp[i+2] ; 
    }
    //for ( int i = 0 ; i < n ; i++ ) cout<<dp[i]<<" " ; cout<<endl ; 
    return dp[0] ; 
}
