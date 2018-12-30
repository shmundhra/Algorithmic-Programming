// https://www.interviewbit.com/problems/regular-expression-ii/

int Solution::isMatch(const string a , const string b) {
    
    string T ( a.begin() , a.end() ) ;
    T.push_back(' ') ;
    
    string P ( b.begin() , b.end() ) ;
    P.push_back(' ') ;
    
    string lauda="";
    char prev = '~';
    for(auto v:P)
    {
        if(v==prev and prev=='*')
            continue;
        else
            lauda+=v;
            prev = v;
    }
    P=lauda;
    
    
    int row = P.size()+1 ; 
    int col = T.size()+1 ; 
    vector < vector<bool> > dp ( row , vector<bool>(col,false) ) ; 
    
    dp[0][0] = true ; 
    
    
    for ( int i = 1 ; i < P.size() ; i++ )
    {   
        int flag = 0 ; 
        for ( int j = 1 ; j <= T.size() ; j++ )
        {
            if ( P[i-1] == '.' )
            {
                if ( P[i] != '*' )
                {
                    dp[i][j] = dp[i-1][j-1] ;     
                }
                else
                {
                    if ( dp[i-1][j-1] )
                    {   
                        flag = 1 ;
                        for ( int k = j-1 ; k <= col ; k++)
                        {
                            dp[i+1][k] = true ; 
                        }
                    }
                }
            }
            else
            {
                if ( P[i] != '*' )
                {
                    dp[i][j] = (int)( dp[i-1][j-1] and (P[i-1] == T[j-1]) ) ;     
                }
                else
                {
                    if ( dp[i-1][j-1] )
                    {   
                        flag = 1 ; 
                        
                        dp[i+1][j-1] = true ; 
                        for ( int k = j ; k <= col and P[i-1]==T[k-1] ; k++ )
                        {
                            dp[i+1][k] = true ; 
                        }
                    }
                }
            }
            
        }
        
        if ( flag == 1 ) i++ ; 
    }
    
    for ( int i = 0 ; i < dp.size() ; i++ )
    {
        //for ( int j = 0 ; j < dp[0].size() ; j++ ) cout<<dp[i][j]<<" " ; cout<<endl ; 
    }
    
    return (int)dp[P.size()-1][T.size()-1]  ;
    
    
  /*
    string T ( a.begin() , a.end() ) ;
     T.push_back(' ') ;
    
    string P ( b.begin() , b.end() ) ;
    P.push_back(' ') ;
    
    int row = P.size()+1 ; 
    int col = T.size()+1 ; 
    vector < vector<bool> > dp ( row , vector<bool>( col, false ) ) ; 
    
    dp[0][0] = true ; 
    
    int startC , endC , startN , endN ; 
    
    startN = 1 ; endN = 1 ;
    
    for ( int i = 1 ; i < P.size() ; i++ )
    {   
        startC = startN ; endC = endN ; startN = 0 ; endN = 0 ;
        
        //cout<<startC<<" "<<endC<<endl ; 
        
        int flag = 0 ; 
        for ( int j = startC ; j <= endC ; j++ )
        {
            if ( P[i-1] == '.' )
            {
                if ( P[i] != '*' )
                {   
                    if ( dp[i-1][j-1] )
                    {
                        dp[i][j] = true ;
                        
                        if (!startN) startN = max(startC+1,j) ; 
                        
                        endN = min( j+1, col-1 ) ; 
                    }
                }
                else
                {
                    if ( dp[i-1][j-1] )
                    {   
                        flag = 1 ;
                        
                        if (!startN) startN = j ;
                        
                        for ( int k = j-1 ; k <= T.size() ; k++)
                        {
                            dp[i+1][k] = true ; 
                        }
                        endN = T.size() ; 
                    }
                }
            }
            else
            {
                if ( P[i] != '*' )
                {   
                    if ( dp[i-1][j-1] and (P[i-1] == T[j-1]) )
                    {
                        dp[i][j] = true ;  
                        
                        if (!startN) startN = max(startC+1,j) ; 
                        endN = min( j+1, col-1 ) ; 
                    }
                }
                else
                {
                    if ( dp[i-1][j-1] )
                    {   
                        flag = 1 ; 
                        
                        dp[i+1][j-1] = true ; 
                        
                        if (!startN) startN = j ; 
                        
                        int k ; 
                        for ( k = j ; k <= T.size() and P[i-1]==T[k-1] ; k++ )
                        {
                            dp[i+1][k] = true ; 
                        }
                        
                        endN = min( col-1 , k) ; 
                    }
                }
            }
            
        }
        if ( flag == 1 ) i++ ; 
        
        //for ( int j = 0 ; j < dp[0].size() ; j++ ) cout<<dp[i][j]<<" " ; cout<<endl ;
    }
    
    for ( int i = 0 ; i < dp.size() ; i++ )
    {
        //for ( int j = 0 ; j < dp[0].size() ; j++ ) cout<<dp[i][j]<<" " ; cout<<endl ; 
    }
    
    return (int)dp[P.size()-1][T.size()-1]  ;*/
    
}