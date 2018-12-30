// https://www.interviewbit.com/problems/nqueens/

int solve ( vector<vector<string> > &ans , vector<string> aux , int A , int row )
{
    if ( row >= A )
    {
        ans.push_back(aux) ; 
        return 0; 
    }
    
    for ( int i = 0 ; i < A ; i++ )
    {
        if ( aux[row][i] == ' ' )
        {   
            vector < string > temp ( aux.begin() , aux.end() ) ; 
            
            for ( int j = 0 ; j < A ; j++ )
            {
                temp[row][j] = '.' ; 
                temp[ j ][i] = '.' ; 
            }
            
            for ( int x = row , y = i ; x < A and y >=0 ; x++ , y--)
                temp[x][y] = '.' ; 
            for ( int x = row , y = i ; x >=0 and y < A ; x-- , y++)
                temp[x][y] = '.' ; 
                
            for ( int x = row , y = i ; x < A and y < A ; x++ , y++)
                temp[x][y] = '.' ; 
            for ( int x = row , y = i ; x >=0 and y >= 0; x-- , y--)
                temp[x][y] = '.' ;     
                
            temp[row][i] = 'Q' ; 
            
            solve ( ans , temp , A , row+1 ) ; 
        }
    }
}



vector<vector<string> > Solution::solveNQueens(int A) {

    vector < string > aux ( A , string( A, ' ' ) ) ; 
    vector<vector<string> > ans ; 
    
    solve ( ans , aux , A , 0 ) ; 
    
    return ans ; 
    
}
