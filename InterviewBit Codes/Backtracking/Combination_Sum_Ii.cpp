// https://www.interviewbit.com/problems/combination-sum-ii/

int solver ( vector< vector<int> > &ans , vector<int> &A ,int B , vector<int> v , int ind )
{
    if ( B < 0 ) return 0 ; 
    if ( B == 0 )
    {
        ans.push_back(v) ; 
        return 0 ; 
    }
    for ( int i = ind ; i < (int)A.size() ;  )
    {
        vector<int> temp ( v.begin() , v.end() ) ; 
        temp.push_back(A[i]) ; 
        solver ( ans , A , B-A[i] , temp , i+1 ) ; 
        
        for ( int j = i ; A[j]==A[i] ; i++ ) ; 
    }
    
}


vector<  vector<int> > Solution::combinationSum(vector<int> &A, int B) {

    sort ( A.begin() , A.end() ) ; 
    vector<int> v ; 
    
    vector<  vector<int> > ans ; 
    
    solver ( ans , A , B , v , 0 ) ; 
    
    return ans ; 
}
