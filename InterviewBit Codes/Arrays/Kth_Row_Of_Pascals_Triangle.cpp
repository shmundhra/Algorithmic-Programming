// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

vector<int> Solution::getRow(int A) {
    vector < int > V ; 
    V.assign ( A+1 , 0 ) ; 
    
    V[0] = 1 ; 
    
    for ( int i = 1 ; i <= A ; i++ )
    {
        for ( int j = i ; j >= 1 ; j-- )
        {
            V[j] = V[j] + V[j-1] ; 
        }
    }
    
    return V ; 
}
