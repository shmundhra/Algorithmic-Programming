// https://www.interviewbit.com/problems/bulbs/

int Solution::bulbs(vector<int> &A) {

    int count = 0 ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        if ( count%2 == A[i] ) count++ ; 
        
        
    }
    return count ; 
}
