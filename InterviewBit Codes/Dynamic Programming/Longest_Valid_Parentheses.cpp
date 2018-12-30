// https://www.interviewbit.com/problems/longest-valid-parentheses/

int Solution::longestValidParentheses(string A) {

    int n = A.size() ;  
    
    if ( !n ) return 0 ; 
    /*
    vector < vector < int > > dp ( n+1 , vector < int > ( n+1 , 0 ) ) ; 
    
    for ( int i = 1 ; i <= n  ; i++ ) dp[i][i-1] = 1 ; 
    
    for ( int len = 1 ; len < n ; len+=2 )
    {
        for ( int start = 0 ; start+len < n+1 ; start++ )
        {   
            for ( int j = 1 ; j <= len ; j+=2 )
            {
                if ( A[start] == '(' and A[start+j] == ')' )
                {
                   dp[start][start+len] = dp[start+1][start+j-1] * dp[start+j+1][start+len]; 
                   if ( dp[start][start+len] ) break ; 
                }
            }
        }
    }
    
    for ( int diff = n%2 ? n-2 : n-1 ; diff >= -1 ; diff -=2 )
    {
        for ( int i = 0 , j = i + diff ; i < n and j < n ; i++ , j++ )
        {
            if ( dp[i][j] != 0 ) 
                return diff+1 ; 
        }
    }*/
    
    stack < char > s ;
    s.push(A[0]) ; 
    
    vector < long long > dp ( n , 0 ) ; 
    
    for ( int i = 1 ; i < n ; i++ )
    {
        if ( A[i] == '(' ) 
        {
            s.push(A[i]) ; 
            dp[i] = dp[i-1] ; 
        }
        else if ( s.top() == '(' ) //   A[i] == ')' and s.top() == '('
        {
            s.pop() ; 
            dp[i] = dp[i-1] + 2 ; 
        }
    }
    for ( int i = 0 ; i < n ; i++ ) cout<<dp[i]<<" " ; 
    
}
