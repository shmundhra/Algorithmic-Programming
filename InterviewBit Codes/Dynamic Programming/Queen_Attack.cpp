// https://www.interviewbit.com/problems/queen-attack/

typedef long long ll ; 
vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    
    if ( A.empty() ) return vector < vector<int> > (0) ; 
    ll row = A.size() ; 
    ll col = A[0].size() ; 
    
    
    /* 
    vector < vector < int > > dp ( row , vector < int > ( col , 0 ) );
    
    for ( ll i = 0 ; i < row ; i++ )
    {   
        for ( ll j = 0 , count = 0  ; j < col ; j++ )
        {   
            dp[i][j] += count ; 
            if ( A[i][j] == '1' ) count = 1 ; 
        }
        for ( ll j = col-1 ,count = 0 ; j >= 0 ; j-- )
        {   
            dp[i][j] += count ; 
            if ( A[i][j] == '1' ) count = 1 ; 
        }
    }
    
    for ( ll j = 0 ; j < col ; j++ )
    {   
        for ( ll i = 0 , count = 0 ; i < row ; i++ )
        {
            dp[i][j] += count ; 
            if ( A[i][j] == '1' ) count = 1 ; 
        }
        for ( ll i = row-1 , count = 0 ; i >= 0 ; i-- )
        {
           dp[i][j] += count ; 
           if ( A[i][j] == '1' ) count = 1 ; 
        }
    }
    
    for ( ll sum = 0 ; sum < row+col-1 ; sum++ )
    {   
        for ( ll i = sum > row-1 ? row-1 : sum , j = sum - i , count = 0 ; i >= 0 and j < col ; i-- , j++ )
        {
            dp[i][j] += count ; 
            if ( A[i][j] == '1' ) count = 1 ; 
        }
        for ( ll j = sum > col-1 ? col-1 : sum , i = sum - j , count = 0 ; j >= 0 and i < row ; j-- , i++ )
        {
            dp[i][j] += count ; 
            if ( A[i][j] == '1' ) count = 1 ; 
        }
    }
    
    for ( ll diff = row-1 ; diff >= 1-col ; diff-- )
    {
        ll count = 0 ; 
        for ( ll i = diff < 0 ? 0 : diff ,  j = i - diff , count = 0 ; i < row and j < col ; i++ , j++ )
        {
            dp[i][j] += count ; 
            if ( A[i][j] == '1' ) count = 1 ; 
        }
        for ( ll i = diff < 0 ? 0 : diff ,  j = i - diff , count = 0 ; i < row and j < col ; i++ , j++ )
        {
            dp[row-1-i][col-1-j] += count ; 
            if ( A[row-1-i][col-1-j] == '1' ) count = 1 ; 
        }
    }
    */
    
    int dp1[row][col] ; 
    
    for ( int i = row-1 ; i >= 0 ; i-- )
    {
        for ( int j = col-1 ; j>= 0 ; j-- )
        {
            int count = 0 ; 
            if ( j+1 < col )
            {   
                count += ( (dp1[i][j+1]/1)%10 or ( A[i][j+1] == '1' ) )*1 ;
            }
            if ( i+1 < row )
            {   
                count += ( (dp1[i+1][j]/100)%10 or ( A[i+1][j] == '1' )  )*100 ;
            }
            if (i+1 < row and j+1< col )
            {   
                count += ( (dp1[i+1][j+1]/10)%10 or ( A[i+1][j+1] == '1' )  )*10 ;
            }
            if ( j > 0 and i+1 < row )
            {   
                count += ( (dp1[i+1][j-1]/1000)%10 or ( A[i+1][j-1] == '1' )  )*1000 ;
            }
            dp1[i][j] = count ; 
        }
    }
    
   int dp2[row][col] ; 
    
    for ( int i = 0 ; i < row ; i++ )
    {
        for ( int j = 0 ; j < col ; j++ )
        {
            int count = 0 ; 
            
            if ( j > 0 )
            {   
                count += ( (dp2[i][j-1]/1)%10 or ( A[i][j-1] == '1' ) )*1 ;
            }
            if ( i > 0 )
            {   
                count += ( (dp2[i-1][j]/100)%10 or ( A[i-1][j] == '1' )  )*100 ;
            }
            if ( i > 0 and j > 0 )
            {   
                count += ( (dp2[i-1][j-1]/10)%10 or ( A[i-1][j-1] == '1' )  )*10 ;
            }
            if ( i > 0 and j+1 < col )
            {   
                count += ( (dp2[i-1][j+1]/1000)%10 or ( A[i-1][j+1] == '1' )  )*1000 ;
            }
            dp2[i][j] = count ; 
        }
    }
    
    vector <vector < int > > dp ( row , vector < int > ( col , 0 ) ); 
    
    for ( int i = 0 ; i < row ; i++ )
        for ( int j = 0 ; j < col ; j++ )
            for ( int place = 0 ; place < 4 ; place++ )
            {
                dp[i][j] = dp[i][j] + ( ( dp1[i][j] + dp2[i][j] )/(int)pow(10,place) ) % 10  ; 
            }
            
    return dp ; 
    
}
