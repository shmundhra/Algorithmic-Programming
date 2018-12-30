// https://www.interviewbit.com/problems/subsets-ii/

/*
int solve ( vector<vector<int> > &ans, vector<int> &A, vector<int> v, int ind  )
{
    ans.push_back(v) ; 
    //if ( ind >= A.size() ) return 0 ;     Optional really 
    
    for ( int i = ind ; i < (int)A.size() ; )
    {
        v.push_back( A[i] ) ; 
        solve ( ans , A , v , i+1 ) ; 
        v.pop_back() ; 
        
        for ( int j = i ; A[j]==A[i] ; i++ ) ; 
    }
}


vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    
    sort ( A.begin() , A.end() ) ;
    
    vector<vector<int> > ans ; 
    vector<int> aux ; 
    
    solve ( ans , A , aux , 0 ) ; 
    
    return ans ; 
}
*/

int solve( vector<vector<int> > &ans, vector<int> &A, vector<int> &v, int ind , int count )
{
    ans.push_back( vector<int>(v.begin() , v.begin()+count) ) ; 
    
    //if ( ind >= A.size() ) return 0 ;     Optional really 
    
    for ( int i = ind ; i < (int)A.size() ; )
    {
        v[count] = A[i] ; 
        solve ( ans , A , v , i+1 , count+1 ) ; 
        
        for ( int j = i ; A[j]==A[i] ; i++ ) ; 
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    
    sort ( A.begin() , A.end() ) ;
    
    vector<vector<int> > ans ; 
    vector<int> aux( (int)A.size() ) ; 
    
    solve ( ans , A , aux , 0 , 0 ) ; 
    
    return ans ; 
}
