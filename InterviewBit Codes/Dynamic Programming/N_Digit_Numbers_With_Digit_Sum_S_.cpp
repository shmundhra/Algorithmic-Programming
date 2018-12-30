// https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/

typedef long long ll ; 
ll mini ( ll a , ll b ) { return a > b ? b : a ; } 

int Solution::solve(int A, int B) {
    
    if (!A) return 0 ; 
    vector < vector < ll  > > dp ( A+1 , vector < ll  > ( B+1 , 0 ) ) ; 
    dp[0][0] = 1 ; 
    
    for ( ll  i = 1 ; i <= A ; i++ )
    {
        for ( ll  j = 1 ; j <= B ; j++ )
        {
            for ( ll  dig = 0 ; dig <= mini(j,9) ; dig++ )
            {
                dp[i][j] = ( dp[i][j] + dp[i-1][j-dig] ) % 1000000007 ; 
            }
        }
    }
    dp[1][0] = 1 ; 
    
    for ( auto v : dp ) 
    {
        //for ( auto x : v ) cout<<x<<" " ; cout<<endl ; 
    }
    return dp[A][B] ; 
}
