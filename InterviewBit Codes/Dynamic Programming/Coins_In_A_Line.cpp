// https://www.interviewbit.com/problems/coins-in-a-line/

vector < vector < long long > > sum ; 
vector < vector < long long > > dpp ; 

long long solve ( vector < int > &A , int start , int end )
{   
    if ( start + 1 == end )
    {
        return max ( A[start] , A[end] ) ; 
    }
    if ( dpp[start][end] == -1 )
    {
        long long f = A[start] + sum[start+1][end]-solve ( A , start + 1 , end ) ; 
        long long l = A[ end ] + sum[start][end-1]-solve ( A , start , end + 1 ) ; 
        dpp[start][end] = f > l ? f : l ; 
    }
    return dpp[start][end] ; 
}

int Solution::maxcoin(vector<int> &A) {
    
    int n = A.size() ; 
    if ( !n ) return 0 ; 
    
    sum.assign( n , vector < long long > ( n , -1 ) ) ;
    dpp.assign( n , vector < long long > ( n , -1 ) ) ;
    
    for ( int i = 0 ; i < n ; i++ ) 
    {
        sum[i][i] = A[i] ; 
        for ( int j = i+1 ; j < n ; j++ )
        {
            sum[i][j] = sum[i][j-1] + A[j] ; 
        }
    }
    
    long long ans = solve ( A , 0 , n-1 ) ; 
    return ans ; 
    
}


/*
long long maxi ( long long a , long long b ) { return a > b ? a : b ; } 

int Solution::maxcoin(vector<int> &A) {
    
    int n = A.size() ; 
    if ( !n ) return 0 ; 
    
    vector < vector < long long > > sum ( n , vector < long long > ( n , -1 ) ) ;
    
    for ( int i = 0 ; i < n ; i++ ) 
    {
        sum[i][i] = A[i] ; 
        for ( int j = i+1 ; j < n ; j++ )
        {
            sum[i][j] = sum[i][j-1] + A[j] ; 
        }
    }
    
    vector < vector < long long > > dp ( n , vector < long long > ( n , -1 ) ) ; 
    
    for ( int i = 0 ; i < n ; i++ ) dp[i][i] = A[i] ; 
    
    for ( int i = 0 ; i+1 < n ; i++ ) dp[i][i+1] = max ( A[i+1] , A[i] ) ; 
    
    for ( int len = 2 ; len < n ; len++ )
    {
        for ( int i = 0 ; i + len < n ; i++ )
        {
            dp[i][i+len] = maxi ( A[i] + ( sum[i+1][i+len] - dp[i+1][i+len] ) , 
                           A[i+len] + (sum[i][i+len-1] - dp[i][i+len-1] ) ); 
        }
    }
    
    return dp[0][n-1] ; 
    
    
    vector < long long > sum ( n+1 , 0 ) ; 
    for ( int i = 0 ; i < n ; i++ ) sum[i+1] = sum[i] + A[i] ; 
    
    vector < long long > dpp ( 2*n-1 , -1 ) ; 
    
    for ( int i = 0 ; i < n ; i++ ) dpp[i+i] = A[i] ; 
    
    for ( int i = 0 ; i+1 < n ; i++ ) dpp[i+i+1] = max ( A[i+1] , A[i] ) ; 
    
    for ( int len = 2 ; len < n ; len++ )
    {
        for ( int i = 0 ; i + len < n ; i++ )
        {
            dpp[i+i+len] = maxi ( A[i] + ( -sum[i+1] + sum[i+len+1] - dpp[i+1+i+len] ) , 
                           A[i+len] + ( -sum[i] + sum[i+len-1+1] - dpp[i+i+len-1] ) ); 
        }
    }
    
    return dpp[0+n-1] ; 
    
}
*/
