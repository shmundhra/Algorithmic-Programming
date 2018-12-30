// https://www.interviewbit.com/problems/diffk-ii/

int Solution::diffPossible(const vector<int> &A, int B) {

    unordered_map < long int , int > m ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        if ( m.find ( A[i] + B ) != m.end() ) return 1 ; 
        if ( m.find ( A[i] - B ) != m.end() ) return 1 ; 
        m [ A[i] ] = i ; 
    }
    return 0 ; 
}
