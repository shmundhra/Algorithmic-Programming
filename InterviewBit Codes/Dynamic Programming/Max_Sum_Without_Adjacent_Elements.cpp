// https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/

typedef long long ll ; 
ll maxi ( ll a , ll b ) { return a > b ? a : b ; } 

int Solution::adjacent(vector<vector<int> > &A) {
    
    if ( A.empty() ) return 0 ; 

    int n = A[0].size() ; 
    
    vector < ll > v ( n ) ; 
    
    for ( int i = 0 ; i < n ; i++ ) v[i] = max( A[0][i] , A[1][i] ) ;
    
    if ( n == 1 ) return v[0] ; 
        
    vector < ll > dp ( n , 0 ) ;
    dp[n-1] = v[n-1] ;
    dp[n-2] = v[n-2] ; 
    
    for ( int i = n-3 ; i >= 0 ; i-- )
    {
        dp[i] = maxi ( dp[i+1] , v[i] + dp[i+2] ) ; 
        dp[i+1] = maxi ( dp[i+1] , dp[i+2] ) ; 
    }
    
    return maxi(dp[0],dp[1]) ; 
}
