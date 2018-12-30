// https://www.interviewbit.com/problems/coin-sum-infinite/

int Solution::coinchange2(vector<int> &A, int B) {
    
    sort ( A.begin() , A.end() ) ; 
    
    vector < int > dp ( B+1 , 0 ) ; 
    dp[0] = 1 ; 
    
    for ( auto a : A )
    {
        for ( int j = 0 ; j <= B ; j++ )
        {
            if ( dp[j] and j+a <= B ) dp[ j+a ] = ( dp[j+a] + dp[j] ) % 1000007 ; 
        }
        //cout<<dp[B]<<" " ; 
    }
    return dp[B] ; 
}
