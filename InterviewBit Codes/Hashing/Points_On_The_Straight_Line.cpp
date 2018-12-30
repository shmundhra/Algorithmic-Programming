// https://www.interviewbit.com/problems/points-on-the-straight-line/

typedef pair< float , float > pairFF ;
    
    
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const pair<T1, T2> &pairFF) const
    {
        return std::hash<T1>()(pairFF.first) ^ std::hash<T2>()(pairFF.second);
    }
};

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    set < pair<int , int> > s ; 
    for ( int i = 0 ; i < A.size() ; i++ )
    {  
        s.insert( make_pair(A[i],B[i])  ) ; 
    }
    A.clear() ; 
    B.clear() ; 
    
    for ( auto it = s.begin() ; it != s.end() ; it++ )
    {
        A.push_back(it->first) ; 
        B.push_back(it->second) ; 
    }
    
    if ( A.size() <= 2 ) return A.size() ; 
    
    long max1 = 0 ; 
    
    unordered_map < int , int > X ; 
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        X[A[i]]++ ; 
       if ( max1 < X[A[i]] ) max1 = X[A[i]] ; 
    }
    
    long max2 = 0 ; 
    unordered_map < pairFF , int , pair_hash  > M ; 
    for ( int i = 1 ; i < A.size() ; i++ )
    {
        for ( int j = 0 ; j < i ; j++ )
        {
            if ( A[i] == A[j] ) continue ; 
            
            float x1 = A[i] ; float y1 = B[i] ; 
            float x2 = A[j] ; float y2 = B[j] ; 
            
            float m = (y2-y1)/(x2-x1) ; 
            float c = (-m)*x2 + y2 ;
            
            pairFF p = make_pair(m,c) ; 
            
            M[ p ]++ ; 
            if( max2 < M[p] ) max2 = M[p] ; 
        }
    }
    
    long long low = 1 ; 
    long long high = INT_MAX ; 
    
    while ( low <= high )
    {
        long long mid = low + ( high - low ) / 2 ; 
        long long answer = mid * (mid-1) / 2  ;
        
        //cout<<answer<<" "<<mid<<endl; 
        
        if ( answer == max2 ) return ( mid > max1 ? mid : max1 ) ;  
        
        if ( answer <  max2 ) low = mid+1 ; 
        
        else high = mid - 1 ; 
    }
    
}
