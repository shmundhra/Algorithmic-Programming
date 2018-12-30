// https://www.interviewbit.com/problems/rain-water-trapped/

int Solution::trap(const vector<int> &A) {
    
    /*stack<int> s ;
    int n = A.size() ; 
    
    vector < int > v ; 
    for ( int i = 0 ; i < A.size() ; i++ ) v.push_back(i) ; 
    
    vector < int > area ( A.size() , 0 ) ; 
    
    s.push( n-1 ) ; 
    
    for ( int i = n-2 ; i >= 0 ; i-- )
    {
        if ( A[i] < A[ s.top() ]  ) 
        {
            v[i] = s.top() ; 
        }
        else
        {
            while( !s.empty() and A[ s.top() ] <= A[i] ) s.pop() ; 
            
            if ( !s.empty() ) v[i] = s.top() ; 
        }
    }
    
    for ( int p = 0 ; p < A.size() ; p++ ) cout<<v[p]<<" " ; cout<<endl ; 
    
    long ans = 0 ; 
    
    for ( int j = 0 ; j < A.size() ; j = max(v[j],j+1) )
    {
        for ( int k = j+1 ; k < v[j] ; k++ )
        {   
            area[k] = A[j]-A[k] ; 
            ans += area[k] ;     
        }
    }
    for ( int p = 0 ; p < A.size() ; p++ ) cout<<area[p]<<" " ; cout<<endl ; 
    
    return ans ; 
    */
    int n = A.size() ; 
    
    int maxi ; 
    
    vector < int > maxl ( n , 0 ) ; 
    vector < int > maxr ( n , 0 ) ;
    vector < int > area ( n , 0 ) ;
    
    maxi = 0 ; 
    for ( int i = 0 ; i < n ; i++ )
    {
        maxi = max ( maxi , A[i] ) ;
        maxl[i] = maxi ; 
    }
    
    
    maxi = 0 ; 
    for ( int i = n-1 ; i >= 0 ; i-- )
    {
        maxi = max ( maxi , A[i] ) ;
        maxr[i] = maxi ; 
    }
    
    
    long ans = 0 ; 
    
    for ( int j = 0 ; j < A.size() ; j++  )
    {
        area[j] = max ( 0 , min ( maxl[j] , maxr[j] ) - A[j] ) ; 
            ans += area[j] ;     
    }
    /*
    for ( int p = 0 ; p < A.size() ; p++ ) cout<<maxl[p]<<" " ; cout<<endl ; 
    for ( int p = 0 ; p < A.size() ; p++ ) cout<<maxr[p]<<" " ; cout<<endl ;     
    for ( int p = 0 ; p < A.size() ; p++ ) cout<<area[p]<<" " ; cout<<endl ; 
    */
    return (int)ans ; 
}
