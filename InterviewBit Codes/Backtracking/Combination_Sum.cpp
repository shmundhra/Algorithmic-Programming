// https://www.interviewbit.com/problems/combination-sum/

/*
int solver ( vector<vector<int> > &ans ,  vector<int> &A , int B ,  vector<int> v )
{
    if ( B <  0 ) return 0; 
    if ( B == 0 ) 
    {
        ans.push_back(v) ; 
    }
    for ( int i = 0 ; i < A.size() ; i++ )
    {   
        vector < int > temp ( v.begin() , v.end() ) ; 
        temp.push_back(A[i]) ; 
        solver ( ans , A , B-A[i] , temp ) ; 
    }
    
}
*/

int solver ( vector<vector<int> > &ans ,  vector<int> &A , int B ,  vector<int> v , int ind)
{
    if ( B <  0 ) return 0; 
    if ( B == 0 ) 
    {
        ans.push_back(v) ; 
        return 0 ; 
    }
    for ( int i = ind ; i < A.size() ; i++ )
    {   
        vector < int > temp ( v.begin() , v.end() ) ; 
        temp.push_back(A[i]) ; 
        solver ( ans , A , B-A[i] , temp , i ) ; 
    }
    
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    set <int> s ( A.begin() , A.end() ) ; 
    A.clear() ; 
    A.assign(s.begin() , s.end() ) ; 
    
    vector<int> v ; 
    
    vector< vector<int> > ans ; 
    /*
    solver ( ans , A , B , v ) ; 
    
    for ( int i = 0 ; i < ans.size() ; i++ )
    {
        sort(ans[i].begin() , ans[i].end() )  ; 
    }
    
    set < vector <int> > s ( ans.begin() , ans.end() ) ; 
    vector< vector<int> > res ( s.begin() , s.end() ) ; 
    
    return res ;
    */
    solver (  ans , A , B , v , 0 ) ; 
    return ans ; 
    
}
