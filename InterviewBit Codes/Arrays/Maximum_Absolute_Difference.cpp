// https://www.interviewbit.com/problems/maximum-absolute-difference/

int Solution::maxArr(vector<int> &A) {
    
    int maxi = INT_MIN ; 
    int dmax = A[0]-0 ; 
    int smin = A[0]+0 ; 
    
    int s , d ; 
    
    for ( int j = 1 ; j < A.size() ; j++ )
    {   
        d = A[j] - j ; 
        s = A[j] + j ; 
        
        maxi = max ( maxi , max ( s - smin , dmax - d ) ) ; 
        
        dmax = max ( dmax , d ) ; 
        smin = min ( smin , s ) ; 
        
    }
    return maxi ; 
}
