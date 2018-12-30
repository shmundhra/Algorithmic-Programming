// https://www.interviewbit.com/problems/equal/

vector<int> Solution::equal(vector<int> &A) {
    
    vector<int> tmp ; 
    vector<int> tmp1 ;
    unordered_map < long int , long int > m ; 
            
    int n = A.size() ;
    
    vector < pair < long int , long int>  > V ; 
    /*
    for ( int i = 0 ; i < n ; i++ ) 
    {
        for ( int j = i+1 ; j < n ; j++ )
        {
            V.push_back( make_pair( A[i]+A[j] , i*n+j ) ) ; 
        }
    }
    
    
    for ( int i = 0 ; i < V.size() ; i++ )
    {
        if ( m.find ( V[i].first ) == m.end() ) 
        {
            m[ V[i].first ] = V[i].second ; 
        }
        else
        {   
            int a , b , c , d ; 
            a = (m[ V[i].first ])/n ; 
            b = (m[ V[i].first ])%n ; 
            c = (V[i].second)/n ; 
            d = (V[i].second)%n ; 
            
            if ( a==c or a == d or b == c or b == d ) continue ; 
            
            if ( tmp.empty() )
            {
                tmp = { a , b , c , d } ; 
            }
            else
            {
                tmp1 = { a , b , c , d } ; 
                
                if ( tmp1 < tmp )
                {
                    tmp.clear() ; 
                    tmp.assign(tmp1.begin() , tmp1.end() ) ; 
                    tmp1.clear() ; 
                }
            }
        }
    }
    */
    
    
    for ( int i = 0 ; i < n ; i++ )
    {
        for ( int j = i+1 ; j < n ; j++ )
        {
            int target = A[i] + A[j] ; 
            unordered_map < long int , long int > m ; 
            
            for ( int k = i+1 ; k < n ; k++ )
            {   
                if ( k == j ) continue ; 
                
                if ( m.find( target - A[k] ) == m.end()  )
                {
                   if ( m.find(A[k]) == m.end() ) 
                        m [ A[k] ] = k ; 
                }
                else
                {   
                    //cout<<i<<" "<<j<<" "<<m[ target-A[k] ]<<" "<<k<<endl ; 
                    
                    if ( tmp.empty() ) 
                        tmp = { i , j , m[target-A[k]] , k } ; 
                    else 
                    {
                        if ( tmp[2] > m[ target - A[k] ] ) 
                        {
                            tmp.clear() ; 
                            tmp = { i , j , m[target-A[k]] , k } ;
                        }
                    }
                }
            }
            if ( !tmp.empty() ) return tmp ; 
        }
    }
    
    return tmp ; 
}
