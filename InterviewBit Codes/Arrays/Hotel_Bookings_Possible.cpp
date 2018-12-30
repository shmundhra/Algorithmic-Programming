// https://www.interviewbit.com/problems/hotel-bookings-possible/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    vector < pair < int , int > > V ; 
    
    for ( int i = 0 ; i < arrive.size() ; i++ )
    {
        V.push_back ( make_pair ( arrive[i] , 1 ) ) ; 
        V.push_back ( make_pair ( depart[i] , -1 ) ) ; 
    }
    sort( V.begin() , V.end() ) ; 
    
    int acti = 0 ; 
    for ( int i = 0 ; i < V.size() ; i++ )
    {
        acti += V[i].second ; 
        if ( acti > K )
            return false ; 
    
    }
        return true ; 
        
    /* LINEAR TIME ALGORITHM but SPACE COMPLEXITY OF ORDER ( MAX VALUED ELEMENT)
    for ( int i = 0 ; i < d.size() ; i++ )
    {
        maxi = max (maxi , d[i] ) ; 
    }
    
    vector <int> hash ; 
    hash.assign( maxi+2 , 0 ) ;
    
    for ( int i = 0 ; i < a.size() ; i++ )
    {
        hash[ a[i] ] += 1 ; 
        hash[ d[i] ] -= 1 ; 
    }
    int M = hash[0] ; 
    for ( int i = 1 ; i < hash.size() ; i++ )
    {
        hash[i] += hash[i-1] ; 
        M = max ( M , hash[i] ) ; 
    }*/
}
