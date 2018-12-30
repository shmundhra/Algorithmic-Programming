// https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> Solution::dNums(vector<int> &A, int B) {
    
    unordered_map<int , int > m ; 
    vector < int > ans ; 
    
    for ( int i = 0 ; i < B ; i++ )
    {
        m[A[i]]++ ; 
    }
    int count = m.size() ; 
    
    for ( int i = B ; i < A.size() ; i++ )
    {
        ans.push_back( count ) ;
        
        if (  m[ A[i-B] ] == 1 ) count -- ; 
        m[ A[i-B] ] -- ; 
        
        if ( m[ A[i] ] == 0 ) count++ ; 
        m [ A[i] ] ++ ; 
    }
    ans.push_back( count ) ;
    return ans ; 
}
