// https://www.interviewbit.com/problems/2-sum/

vector<int> Solution::twoSum(const vector<int> &A, int B) {

    unordered_map < int , int > m ; 
    vector < int > ans ; 
    
    for ( int i = A.size() ; i >= 0 ; i-- )
    {
        if ( m.find ( B - A[i] ) == m.end() )
            m [ A[i] ] = i ; 
        
        else
        {   
            ans.clear() ; 
            ans.assign(2,0) ; 
            ans[1] = m [ B-A[i] ] + 1 ; 
            ans[0] = i + 1 ; 
        }
    }
    return ans; 
}
