// https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/

int maxim ( int a , int b , int c , int d , int e )
{
    return max ( a , max ( max(b,c) , max(d,e) ) ) ; 
}
vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    
    vector <vector<int> > ans ;
    if ( B.empty() or B[0].empty() ) return ans ; 
    
    int r = B.size() ; 
    int c = B[0].size() ; 
    
    vector < vector < vector < int > > > dp ( 2 , vector < vector < int > > ( r+2 , vector < int > ( c+2 , INT_MIN/2 ))); 
    
    for ( int i = 0 ; i < r ; i++ )
    {
        for ( int j = 0 ; j < c ; j++ )
        {
            dp[0][i+1][j+1] = B[i][j] ; 
        }
    }
    
    for ( int k = 1 ; k <= A ; k++ )
    {
        for ( int i = 1 ; i <= r ; i++ )
        {
            for ( int j = 1 ; j <= c ; j++ )
            {
                dp[(k)%2][i][j] = maxim ( dp[(k-1)%2][i][j] , dp[(k-1)%2][i-1][j] , dp[(k-1)%2][i][j-1], dp[(k-1)%2][i+1][j] , dp[(k-1)%2][i][j+1] ) ;
            }
        }
    }
    
    for ( int i = 1 ; i <= r ; i++ )
    {
        for ( int j = 1 ; j <= c ; j++ )
        {
            ans[i-1][j-1] = dp[A%2][i][j] ; 
        }
    }
    return ans ;  
}
