// https://www.interviewbit.com/problems/palindrome-partitioning-ii/

int Solution::minCut(string A) {
    
    int n = A.size() ; 
    
    if ( !n ) return 0 ; 
    
    vector < vector < bool > > dp ( n , vector < bool > ( n , false ) ) ; 
    
    for ( int i = 0 ; i < n ; i++ ) dp[i][i] = 1 ; 
    for ( int i = 0 ; i+1 < n ; i++ ) dp[i][i+1] = (A[i]==A[i+1]) ; 
    
    for ( int len = 2 ; len < n ; len++ )
    {
        for ( int start = 0 ; start + len < n ; start ++ )
        {
            dp[start][start+len] = (A[start] == A[start+len]) and dp[start+1][start+len-1] ;
        }
    }
    /*
    vector < vector < int > > cost ( n , vector < int  > ( n , INT_MAX/2 ) ) ;
    
    for ( int len = 0 ; len < n ; len ++ )
    {
        for ( int start = 0 ; start + len < n ; start++ )
        {
            if ( dp[start][start+len] ) cost[start][start+len] = 0 ; 
            else
            {
                for ( int cut = start ; cut < start+len ; cut++ )
                {   
                    int val = cost[start][cut] + cost[cut+1][start+len] + 1 ; 
                    
                    if ( cost[start][start+len] > val ) 
                    {
                        cost[start][start+len] = val ; 
                    }
                }
            }
        }
    }
    
    return cost[0][n-1] ; 
    */
    
    int count = 0 ; 
    int pos ; 
    for ( int i = 0 ; i < n ; count += ( i<n ) )
    {
        for ( int j = i ; j < n ; j++ )
        {
            if ( dp[i][j] ) pos = j+1 ; 
        }
        i = pos ; 
    }
    return count ; 
}
