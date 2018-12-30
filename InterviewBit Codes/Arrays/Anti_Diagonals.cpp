// https://www.interviewbit.com/problems/anti-diagonals/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    vector < int > W ; 
    vector < vector < int > > V ; 
    
    int N = 2*(A.size()-1) + 1 ;
    
    for ( int i = 0 ; i < N ; i++ )
    {
        V.push_back(W) ; 
    }
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        for ( int j = 0 ; j < A.size() ; j++ )
        {
            V[i+j].push_back( A[i][j] ) ; 
        }
    }
    
    return V ; 
}
