// https://www.interviewbit.com/problems/tushars-birthday-party/

typedef long long ll ; 
int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {

    ll maxcap = *max_element(A.begin() , A.end() ) ; 
    
    vector < vector < ll > > dp ( (ll)B.size()+1 , vector <ll> (maxcap+1 , 0) ) ;
        
    for ( ll i = 0 ; i < dp.size()    ; i++ ) dp[i][0] = 0 ; 
    for ( ll j = 0 ; j < dp[0].size() ; j++ ) dp[0][j] = INT_MAX/2 ;
        
    for ( ll i = 1 ; i < dp.size() ; i++ ) 
    {
        for ( ll j = 1 ; j < dp[0].size() ; j++ )
        {
            dp[i][j] = dp[i-1][j] ; 
            
            if ( j >= B[i-1] and dp[i][ j-B[i-1] ] + C[i-1] < dp[i][j] )
            {
                dp[i][j] = dp[i][ j-B[i-1] ] + C[i-1]  ; 
            }
        }
    }
    ll cost = 0 ; 
    for ( auto cap : A ) cost += (dp.back())[cap] ; 
    
    return cost ; 
    
}
