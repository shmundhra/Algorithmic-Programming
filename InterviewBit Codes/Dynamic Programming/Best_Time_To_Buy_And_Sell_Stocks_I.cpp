// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/

int Solution::maxProfit(const vector<int> &v) {
        
    int n = v.size() ; 
    
    if ( n <= 1 ) return 0 ; 
    
    vector < long long > dp ( n , 0 ) ; 
    
    for ( int i = n-2 ; i >= 0 ; i-- )
    {
       dp[i] = max ( v[i+1] - v[i] , dp[i+1] ) ; 
    }
    return dp[0] ;
}
