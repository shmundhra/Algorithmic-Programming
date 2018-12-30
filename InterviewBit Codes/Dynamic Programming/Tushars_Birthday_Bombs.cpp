// https://www.interviewbit.com/problems/tushars-birthday-bombs/

vector<int> Solution::solve(int R, vector<int> &A) {
    
    
    long long min = INT_MAX ; 
    long long minp = -1 ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        if ( min > A[i] )
        {
            min = A[i] ;
            minp = i ; 
        }
    }
    
    long long num = R/min ; 
    
    long long sum = num*min ; 
    
    vector <int> ans ; 
    
    for ( int i = 0 ; i < minp and num ; ) 
    {
        if ( sum - min + A[i] <= R )
        {   
            sum = sum - min + A[i] ; 
            ans.push_back(i) ; 
            num-- ; 
        }
        else
        {
            i++ ; 
        }
    }
    
    for ( int i = 0 ; i < num ; i++ ) ans.push_back(minp) ; 
    
    return ans ; 
    
    
    
}
