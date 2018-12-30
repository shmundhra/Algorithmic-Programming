// https://www.interviewbit.com/problems/equal-average-partition/

vector<vector<int> > Solution::avgset(vector<int> &A) {
    
    sort ( A.begin() , A.end() ) ; 
    
    int maxsum = accumulate (  A.begin() , A.end() , 0 )  ; 
    
    vector <vector <int >  > dp ( A.size()+1 , vector <int >( maxsum+1 , A.size()+100 ) ); 
    vector <vector <int >  >path( A.size()+1 , vector <int >( maxsum+1 , 0  ) ) ; 
    
    for ( int i = 0 ; i < dp.size() ; i++ ) dp[i][0] = 0 ; 
    
    for ( int i = 1 ; i < dp.size() ; i++ ) 
    {
        for ( int j = 1 ; j < dp[0].size() ; j++ )
        {
            dp[i][j] = dp[i-1][j] ; 
            path[i][j] = 1 ; 
            
            if ( j >= A[i-1] and dp[i][j] > dp[i][ j - A[i-1] ] + 1 )
            {   
                dp[i][j] = dp[i][ j - A[i-1] ] + 1 ;
                path[i][j] = -1 ; 
            }
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
}
