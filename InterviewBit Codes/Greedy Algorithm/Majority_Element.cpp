// https://www.interviewbit.com/problems/majority-element/

int Solution::majorityElement(const vector<int> &A) {
    /*
    vector < int > A ( a.begin() , a.end() ) ;
    
    if ( A.size() < 3) return A[0] ; 
    
    int i , j ;
    for ( i = 0 , j = 1 ; j < A.size() ; )
    {
        if ( A[i] == A[j] )
        {
            j++ ; 
        }
        else
        {
            swap ( A[i+1] , A[j] ) ; 
            i += 2 ; 
            j = max ( j+1 , i+1 ) ; 
        }
    }
    return A[i] ; 
    */
    
    
    int num1 = A[0] ; 
    int count1 = 1 ; 
    
    for ( int j = 1 ; j < A.size() ; j++ )
    {   
         
        if ( count1 == 0 )
        {
            num1 = A[j] ;
            count1++ ; 
            continue ; 
        }
        
        if ( A[j] == num1 )
        {
            count1++ ; 
        }
        else
        {
            count1-- ; 
        }
    }
    return num1 ; 
    
}
