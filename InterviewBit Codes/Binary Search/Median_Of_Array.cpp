// https://www.interviewbit.com/problems/median-of-array/

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size() ; 
    int m = B.size() ;
    
    if ( n < 4 and m < 4 )
    {
        vector < int > v ( A.begin() , A.end() ) ; 
        v.insert( v.end() , B.begin() , B.end() ) ; 
        
        sort ( v.begin() , v.end() ) ; 
        
        if ( v.size() % 2 ) return v[v.size()/2] ; 
        
        return  ( (double)( v[v.size()/2] + v[v.size()/2-1]  ) )/ 2  ; 
    }
    
    if ( n == 0 )
    {
        if ( B.size() % 2 ) return B[B.size()/2] ; 
        
        return  ( (double)( B[B.size()/2] + B[B.size()/2-1]  ) )/ 2  ; 
    }
    
    if ( m == 0 )
    {
        if ( A.size() % 2 ) return A[A.size()/2] ; 
        
        return  ( (double)( A[A.size()/2] + A[A.size()/2-1]  ) )/ 2  ; 
    }
    
    int low = 0 ; 
    int high = n-1 ; 
    
    while ( low < high )
    {
        int midA = low + ( high - low + 1 ) / 2 ; 
        int midB = (n+m)/2 - midA ; 
        
        if ( midB <= m and A[midA] >= B[midB-1] )
        {
            low = midA ; 
        }
        else
        {
            high = midA-1 ; 
        }
    }
    int i = low ; 
    int j = (n+m)/2 - i ; 
    
    cout<<i<<" "<<j<<endl ; 
    
    if ( (n+m)%2 )
    {
        return min ( A[i] , B[j] ) ; 
    }
    else
    {   
        int x = min(A[i],B[j]) ;
        int y = INT_MIN;
        
        if ( i != 0 ) y = max ( y , A[i-1] ) ; 
        if ( j != 0 ) y = max ( y , B[j-1] ) ; 
        
        return ( (double)(x+y) )/ 2  ; 
    }
    
}
