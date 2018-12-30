// https://www.interviewbit.com/problems/spiral-order-matrix-ii/

vector<vector<int> > Solution::generateMatrix(int A) {
    
    vector < vector < int > > V ; 
    
    vector < int > N ; 
    N.assign(A,0) ; 
    
    for ( int i = 0 ; i < A ; i++ )
    {
        V.push_back(N) ; 
    }
    
    int T = 0 ; int R = A-1 ; int B = A-1 ; int L = 0 ; 
    
    int count = 1 ;
    int dir = 0 ; 
    
    while ( T<=B && L<=R )
    {
        switch ( dir )
        {
            case 0 : for ( int j = L ; j <= R ; j++ )
                     {
                         V[T][j] = count++ ; 
                     }
                     T++ ; 
                     break ; 
                     
            case 1 : for ( int j = T ; j <= B ; j++ )
                     {
                         V[j][R] = count++ ; 
                     }
                     R-- ; 
                     break ; 
                     
            case 2 : for ( int j = R ; j >= L ; j-- )
                     {
                         V[B][j] = count++ ; 
                     }
                     B-- ; 
                     break ; 
                     
            case 3 : for ( int j = B ; j >= T ; j-- )
                     {
                         V[j][L] = count++ ; 
                     }
                     L++ ;
                     break ; 
        }
        dir = ( dir + 1 ) % 4 ; 
    }
    
    return V ; 
    
}
