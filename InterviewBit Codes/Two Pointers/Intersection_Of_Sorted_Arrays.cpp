// https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {

    vector < int > v ; 
    
    for ( int i = 0 , j = 0 ; i < A.size() and j < B.size() ; )
    {
        if ( A[i] == B[j] )
        {
            v.push_back( A[i] ) ; 
            i++ ; j++ ; 
        }
        else if ( A[i] > B[j] ) j++ ; 
        else i++ ; 
    }
    
    return v ; 
    
    
}
