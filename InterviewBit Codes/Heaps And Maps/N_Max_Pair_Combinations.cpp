// https://www.interviewbit.com/problems/n-max-pair-combinations/

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    
    int len = A.size() ; 
    
    sort ( A.begin() , A.end() ) ; 
    sort ( B.begin() , B.end() ) ; 
    
    vector < int > VA ( len ) ; 
    vector < int > VB ( len ) ; 
    
    for ( int i = len-1 ; i>0 ; i-- ) VA[i] = i-1 ; 
    for ( int i = len-1 ; i>0 ; i-- ) VB[i] = i-1 ; 
    
    vector < int > C(len,0) ; 
    for ( int i = 0 ; i < len ; i++ ) C[i] = A[i] + B[i] ; 
    
    priority_queue < long int > pq ; 
    
    int count = 0 ; 
    int a , b , a1 , b1 ; 
    
    for ( int p = len-1 ; p >= 0 and count < len ; p-- )
    {   
        int sum = C[p] ; 
        for ( a1 = len-1 ; a1 > p ; a1-- )
        {
            for ( b = VA[a1] ; b >= 0 ; b--)
            {
                if ( A[a1] + B[b] >= sum )    
                {
                    pq.push( A[a1]+B[b] ) ; 
                    count++ ; 
                }
                else 
                {
                    VA[a1] = b ; 
                    break ; 
                }
            }
        }
        for ( b1 = len-1 ; b1 > p ; b1-- )
        {
            for ( a = VB[b1] ; a >= 0 ; a--)
            {
                if ( A[a] + B[b1] >= sum )    
                {
                    pq.push( A[a]+B[b1] ) ; 
                    count++ ; 
                }
                else 
                {
                    VB[b1] = a ; 
                    break ; 
                }
            }
        }
        pq.push(sum) ; 
    }
   
    vector < int > ans ; 
    for ( int k = 0 ; k < len ; k++ )
    {
        ans.push_back( pq.top() ) ; 
        pq.pop() ; 
    }
    
    return ans ;
    
}
