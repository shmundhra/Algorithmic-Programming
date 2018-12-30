// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/

long long max ( long long a , long long b ) { return a > b ? a : b ; } 

int Solution::maxProfit(const vector<int> &A) {
    
    if ( A.empty() ) return 0 ; 
    
    int n = A.size() ; 
    
    vector < long long > dp1 ( n , 0 ) ; vector < long long > dp2 ( n , 0 ) ; 
    
    int maxi = A[n-1] ; 
    for ( int i = n-2 ; i >= 0 ; i-- )
    {
        dp1[i] = max ( dp1[i+1] , maxi - A[i] ) ; 
        maxi = max ( maxi , A[i] ) ; 
    }
    
    vector < int > aux ( n , 0 ) ; 
    for ( int i = 0 ; i < n ; i++ ) aux[i] = A[i] + dp1[i] ;
    
    maxi = aux[n-1] ; 
    for ( int i = n-2 ; i >= 0 ; i-- )
    {
        dp2[i] = max( dp2[i+1] , maxi - A[i] ) ; 
        maxi = max ( maxi , aux[i] ) ;
    }
    
    return dp2[0] ; 
    
}
