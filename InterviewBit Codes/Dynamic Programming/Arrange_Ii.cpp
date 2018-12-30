// https://www.interviewbit.com/problems/arrange-ii/

/*vector < vector < int >  > dp ; 

int solve ( string &S , int index , int stables )
{
    int len = S.size() ; 
    
    if ( stables > ( len - index) ) return INT_MAX ; 
    
    if ( dp[index][stables] == -1 )
    {   
        int w , b ; 
        w = b = 0 ; 
        
        if ( stables == 1 )
        {
            for ( int i = index ; i < len ; i++ )
                if ( S[i] == 'W' ) w++ ; else b++ ; 
            dp[index][stables] = w*b ; 
        }
        else
        {
            int mini = INT_MAX/4 ; 
            for ( int i = index ; i <= len - stables ; i++ )
            {   
                if ( S[i] == 'W' ) w++ ; else b++ ; 
                mini =  min ( mini, w*b + solve(S,i+1,stables-1) ) ;  
            }
            dp[index][stables] = mini ; 
        }
    }
    return dp[index][stables] ; 
}

int Solution::arrange(string A, int B) {
  
    int len = A.length() ; 
  
    if ( B > len ) return -1 ; 
    
    dp.assign ( len , vector < int > ( len , -1 ) ) ;
    
    int ans = solve ( A , 0 , B ) ; 
    
    return ans ; 
    
    return 0 ; 
}*/

int Solution::arrange(string A, int B) {
    
    int len = A.length() ; 
  
    if ( B > len ) return -1 ; 
    
    vector < vector < int > > dp ( 2 , vector < int > ( len , INT_MAX/4 ) ) ; 
    
    int w , b ; 
    w = b = 0 ; 
    
    for ( int i = len - 1 ; i >= 0 ; i-- )
    {
        if ( A[i] == 'W') 
            w++ ; 
        else 
            b++ ;
        dp[0][i] = w*b ; 
    }
    
    for ( int i = 1 ; i < B ; i++ )
    {
        for ( int j = 0 ; j < A.size() ; j++ )
        {   
            int w , b ; 
            w = b = 0 ; 
            for ( int k = j ; k + 1 < A.size() ; k++ )
            {
                if ( A[k] == 'W') 
                    w++ ; 
                else 
                    b++ ; 
                dp[i%2][j] = min ( dp[i%2][j] , w*b + dp[(i-1)%2][k+1]) ; 
            }
        }
    }
    return dp[(B-1)%2][0] ; 
}

