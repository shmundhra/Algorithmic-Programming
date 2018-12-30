// https://www.interviewbit.com/problems/container-with-most-water/

long long area ( vector < int > &A , int i , int j )
{
    return (long long)( j - i ) * (long long) min ( A[i] , A[j] ) ; 
}

long long maxl ( long long a , long long b )
{
    return a < b ? b : a ; 
}
int Solution::maxArea(vector<int> &A) {
    
    // ______________________________BETICHOR O(n) approach with some chodon bug . 
    
    long long maxi = 0 ; 
    
    vector < int > v ; 
    v.push_back(0) ; 
    v.insert( v.end() , A.begin() , A.end() ) ; 
    v.push_back(0) ; 
    
    int start = 1 ; 
    int end = (int)v.size()-2 ; 
    
    int next = start ; 
    int prev = (int)v.size()-2 ;  
    
    while ( start < end )
    {   
        while ( next < v.size()-1 and v[next] <= v[start] ) next ++ ; 
        
        while ( prev > 0 and v[prev] <= v[ end ] ) prev -- ; 
        
        maxi = maxi < area ( v , start , end ) ? area ( v , start , end ) : maxi ; 
        
        //cout<<start<<" "<<end<<": "<< area ( v , start , end ) <<endl ; 
        
        long long a = area ( v , next  , end  ) ; 
        long long b = area ( v , start , prev ) ; 
        
        if ( a < b ) end = prev ; 
        else if ( a > b ) start = next ; 
        else 
        {
            start = next ; 
            end = prev ; 
        }
    }
    
    return (int)maxi ; 
    
// _____________________________________________________________BANTU NLOGN approach :( 
/*
    int maxi = 0 ; 
    
    vector < pair < int , int > > v ; 
    
    int gl , gr ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        v.push_back( make_pair( A[i] , i ) ) ; 
    }
    
    sort ( v.begin() , v.end() ) ; 
    
    gl = gr = v[v.size()-1].second ; 
    
    for ( int i = (int)v.size()-2 ; i >= 0 ; i-- )
    {
        maxi = max ( maxi , v[i].first * (max ( gr - v[i].second , v[i].second - gl)) ) ;
        gr = max ( gr , v[i].second ) ; 
        gl = min ( gl , v[i].second ) ; 
    }
    
    return maxi ;
*/
}
