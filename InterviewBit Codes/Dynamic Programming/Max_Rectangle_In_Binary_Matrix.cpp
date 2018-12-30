// https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

int solve ( vector < int > v )
{   
    v.push_back(-1) ; 
    stack < int > s ; 
    
    vector< int > nextS ( v.size() , v.size() ) ; 
    s.push( v.size()-1 ) ;
    
    for ( int i = (int)v.size()-2 ; i >= 0 ; i-- )
    {   
        while ( v[s.top()] >= v[i] ) s.pop() ; 
        
        nextS[i] = s.top() ; 
        s.push(i) ; 
    }
    v.pop_back() ;
    
    //for ( int i = 0 ; i < nextS.size()-1 ; i++ ) cout<<nextS[i]<<" " ; cout<<endl ; 
     
    v.insert(v.begin() , 1 , -1 ) ; 
    stack < int > r ; 
    
    vector< int > prevS ( v.size() , 0 ) ; 
    s.push( 0 ) ;
    
    for ( int i = 1 ; i < v.size() ; i++ )
    {
        while ( v[s.top()] >= v[i] ) s.pop() ; 
        
        prevS[i-1] = s.top()-1 ; 
        s.push(i) ; 
    }
    v.erase(v.begin() , v.begin()+1 ) ; 
    //for ( int i = 0 ; i < prevS.size()-1 ; i++ ) cout<<prevS[i]<<" " ; cout<<endl ; 
    
    
    int rect = 0 ; 
    for ( int i = 0 ; i < (int)v.size() ; i++ )
    {
        rect = max ( rect , v[i] * ( nextS[i] - prevS[i] - 1) ) ; 
    }
    
    //cout<<rect<<endl<<endl ; 
    
    return rect ; 
}



int Solution::maximalRectangle( vector<vector<int> > &A ) {
    
    if ( A.empty() ) return 0 ; 
    
    int row = A.size() ; 
    int col = A[0].size() ; 
    
    vector<vector<int> > dp ( row , vector <int> ( col , 0 ) ) ; 

    
    for ( int j = 0 ; j < col ; j++ )
    {   
        dp[0][j] = A[0][j] ; 
        for ( int i = 1 ; i < row ; i++ )
        {
            if ( A[i][j] )
            {
                dp[i][j] = dp[i-1][j] + 1 ; 
            }
        }
    }
    
    for ( int i = 0 ; i < row ; i++ ) 
    {
        //for ( int j = 0 ; j < col ; j++ ) cout<<dp[i][j]<<" " ; cout<<endl ; 
    }
    
    int maxi = 0 ; 
    for ( int i = 0 ; i < row ; i++ ) maxi = max ( maxi , solve(dp[i]) ) ; 
    
    return maxi ; 
    
}
