// https://www.interviewbit.com/problems/find-permutation/

vector<int> Solution::findPerm(const string A, int B) {
    
    vector < int > ans (B, 0 ) ; 
    int max = 1 ; int min = 1 ; 
    
    ans[0] = 1 ; 
    
    for ( int i = 0 ; i < A.size() ; i++ ) 
    {
        if ( A[i] == 'I' ) 
        {
            ans[i+1] = ++max ; 
        }
        else
        {
            ans[i+1] = --min ; 
        }
    }
    
    if ( min < 1 )
    {
        for ( int i = 0 ; i < B ; i++ )
            ans[i] = ans[i] + 1 - min ; 
    }
    
    return ans ;
    
    
}
