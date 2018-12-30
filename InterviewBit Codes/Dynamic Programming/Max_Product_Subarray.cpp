// https://www.interviewbit.com/problems/max-product-subarray/

long long max ( long long a , long long b ){ return a < b ? b : a ; }

int Solution::maxProduct(const vector<int> &v) {
    
    /*
    vector < vector < int > > v ; 
    v.push_back(vector<int>(0) ) ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        if ( A[i] != 0 )
            v[v.size()-1].push_back(A[i]);
        else
        {
            if ( !v[v.size()-1].empty() ) v.push_back(vector<int>(0) ) ;
        }
    }
    for ( int i = 0 ; i < v.size() ; i++ )
    {
      //for ( auto x : v[i] ) cout<<x<<" " ; cout<<endl ; 
    }
    
    
    long long prod ; 
    long long maxp = INT_MIN ; 
    
    for ( int i = 0 ; i < v.size() ; i++ )
    {   
        if ( v[i].size() == 0 ) 
        {
            maxp = max ( maxp , 0 ) ;  
            continue ;
        }
        if ( v[i].size() == 1 )
        {
            maxp = max ( maxp , v[i][0] ) ; 
            continue ; 
        }
        
        int first = -1 ; 
        int last = -1 ; 
        prod = 1 ; 
        for ( int j = 0 ; j < v[i].size() ; j++ )
        {
            prod *= v[i][j] ; 
            if ( v[i][j] < 0 )
            {
                if ( first == -1 ) first = j ; 
                last = j ; 
            }
        }
        if ( prod > 0 ) 
        {
            maxp = max( maxp , prod ) ; 
        }
        else
        {   
            long long left = 1 ; 
            for ( int j = 0 ; j <= first ; j++ )
            {
                left *= v[i][j];
            }
            
            long long right = 1 ; 
            for ( int j = last ; j < v[i].size() ; j++ )
            {
                right *= v[i][j];
            }
            
            maxp = max ( maxp , max ( prod/left , prod/right ) ) ; 
        }
        
    }
    
    return maxp ; 
    */
   
    if ( v.size() == 1 ) return v.front() ; 
    v.push_back(0) ; 
    
    long long pos , neg , maxp ; 
    pos = neg = INT_MIN ; 
    maxp = INT_MIN ; 
    
    for ( int i = 0 ; i < v.size() ; i++ )
    {
        if ( v[i] == 0 )
        {   
            maxp = max( max(pos,neg) , max(maxp,0) ) ; 
            pos = neg = INT_MIN ; 
        }
        else
        {
            if ( v[i] > 0 ) 
            {   
                if ( pos == INT_MIN ) pos = 1 ; 
                pos *= v[i] ; 
                if ( neg != INT_MIN ) neg *= v[i] ;
            }
            else 
            {
                maxp = max ( maxp , pos ) ; 
                if ( neg != INT_MIN ) pos = neg*v[i] ; 
                else pos = INT_MIN ; 
                neg = v[i] ; 
            }
        }
    }
    return maxp ; 
    
    
    
}
