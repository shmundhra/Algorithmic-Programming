// https://www.interviewbit.com/problems/maximum-unsorted-subarray/

vector<int> Solution::subUnsort(vector<int> &A) {
    
    
    int i ; 
    for ( i = 0 ; i < A.size()-1 ; i++ )
    {
        if ( A[i] > A[i+1] ) 
            break ;
    }
    
    int j ; 
    int mini = INT_MAX ; 
    for ( j = i+1 ; j < A.size() ; j++ )
        mini = min ( mini , A[j] ) ; 
        
    int l = upper_bound ( A.begin() , A.begin() + i + 1 , mini ) - A.begin() ; 
    
    
    for ( i = A.size()-1 ; i > 0 ; i-- )
    {
        if ( A[i] < A[i-1] ) 
            break ;
    }
    
     
    int maxi = INT_MIN ; 
    for ( j = i-1 ; j >=0 ; j-- )
        maxi = max ( maxi , A[j] ) ; 
        
    int r = lower_bound ( A.begin()+i , A.end() , maxi ) - A.begin() - 1 ;
    
    vector < int > ans ; 
    if ( i == 0 ) 
        ans.push_back(-1) ; 
    else
    {
        ans.push_back(l) ; 
        ans.push_back(r) ; 
    }
    
    return ans ;
    
    
}

