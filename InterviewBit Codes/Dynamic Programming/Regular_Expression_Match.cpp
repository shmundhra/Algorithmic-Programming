// https://www.interviewbit.com/problems/regular-expression-match/

int Solution::isMatch(const string a, const string B) {
     /*
    string A ( a.begin() , a.end() ) ; 
    
    A.push_back('*') ; 
        
    int col = A.size()+1 ;
    
    vector < int > dp ( col , 0 )  ; 
    dp[0] = 1 ; 

    int prev , curr ; 
    
    for ( int i = 1 ; i <= B.size() ; i++ )
    {   
        curr = 0 ;  
        for ( int j = 1 ; j <= A.size() ; j++ )
        {   
            prev = dp[j-1] ; 
            dp[j-1] = curr ; 

            if ( B[i-1] == '?' ) 
            {
                curr = prev ;                
            }
            else if ( B[i-1] == '*' )
            {
                if ( prev )
                {
                    for ( int k = j-1 ; k < col ; k++ )
                    {
                        dp[k] = 1 ; 
                    }
                    break ; 
                }
                continue ; 
            }
            else
            {
                curr = ( prev and (B[i-1] == A[j-1]) ) ; 
                continue ; 
            }
            
        }
        //for ( int k = 0 ; k < dp.size() ; k++ ) cout<<dp[k]<<" " ; cout<<endl ; 
    }
    
    return !(!dp[col-2]) ; 
    */

    string A ( a.begin() , a.end() ) ; 
    
    A.push_back('*') ; 
    
    int row = B.size()+1 ; 
    int col = A.size()+1 ;
    
    vector < vector < bool > > dp (row , vector < bool > ( col , 0 ) ) ; 
    dp[0][0] = 1 ; 
    
    for ( int i = 0 ; i < B.size() ; i++ )
    {   
        if ( B[i] == '*' and dp[i][0] ) dp[i+1][0] = 1 ; 
        
        for ( int j = 0 ; j < A.size() ; j++ )
        {
            if ( B[i] == '?' ) 
            {
                dp[i+1][j+1] = dp[i][j] ; 
                continue ; 
            }
            else if ( B[i] == '*' )
            {
                if ( dp[i][j] )
                {
                    for ( int k = j ; k < col ; k++ )
                    {
                        dp[i+1][k] = 1 ; 
                    }
                    break ; 
                }
                continue ; 
            }
            else
            {
                dp[i+1][j+1] = ( dp[i][j] and (B[i] == A[j]) ) ; 
                continue ; 
            }
        }
    }
    /*for ( int i = 0 ; i < row ; i++ )
    {   for ( int j = 0 ; j < col ; j++ )
            cout<<dp[i][j]<<" " ; 
        cout<<endl ; 
    }*/
    return !(!dp[B.size()][A.size()-1]) ; 

}