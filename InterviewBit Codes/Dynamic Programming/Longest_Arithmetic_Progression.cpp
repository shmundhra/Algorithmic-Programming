// https://www.interviewbit.com/problems/longest-arithmetic-progression/

int Solution::solve(const vector<int> &A) {
    
    if ( A.empty() ) return 0 ; 
   
    vector < vector < pair<long long,int> > > v ( A.size() ) ; 
    
    int maxlen = 1 ; 
    
    for ( int i = 1 ; i < A.size() ; i++ )
    {   
        for ( int j = i ; j < A.size() ; j++ )
        {
            v[i-1].push_back( { A[j]-A[i-1] , 1 } ) ; 
        }
        
        for ( int j = i-1 ; j >= 0 ; j-- )
        {
            long long diff = A[i] - A[j] ; 
            
            int flag = 0 ;
            
            for ( int k = 0 ; k < v[i].size() ; k++ )
            {
                if ( v[i][k].first == diff )
                {
                    flag = 1 ; 
                    break ; 
                }
            }
            
            if ( flag ) continue ; 
            
            for ( int k = 0 ; k < v[j].size() ; k++ )
            {
                if ( v[j][k].first == diff )
                {
                    v[i].push_back( { diff , v[j][k].second + 1 } ) ;     
                    maxlen = max ( maxlen , (v[i].back()).second ) ; 
                }
            }
        }
    }
    return maxlen ; 
    
    /*
    if ( A.empty() ) return 0 ; 
    
    map < long , int > M[(int)A.size()] ; 
    int maxi = 0 ; 
    for ( int i = 1 ; i < A.size() ; i++ )
    {
        for ( int j = 0 ; j < i ; j++ )
        {
            M[i][ A[i]-A[j] ] = M[j][ A[i]-A[j] ] + 1 ; 
            maxi = max ( maxi , M[i][ A[i] - A[j] ]) ; 
        }
    }
    return maxi+1 ; 
    */
    
    
    
    
}
