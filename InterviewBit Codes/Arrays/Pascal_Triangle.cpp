// https://www.interviewbit.com/problems/pascal-triangle/

vector<vector<int> > Solution::generate(int A) {
    
    vector < vector < int > > V ; 
    
     
    
    for ( int i = 1 ; i <= A ; i++ )
    {
        vector < int > W ;
        W.assign( i , 1 ) ; 
        V.push_back(W) ; 
    }
    
    for ( int i = 0 ; i < A ; i++ )
    {
        for ( j = 1 ; j < i ; j++ )
        {
            A[i][j] = A[i-1][j] + A[i-1][j-1] ; 
        }
    }
        
}
