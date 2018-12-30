// https://www.interviewbit.com/problems/4-sum/

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    
    sort ( A.begin() , A.end() )  ; 
    
    //for ( int i = 0 ; i < A.size() ; i++ ) cout<<A[i]<<" " ; cout<<endl ; 
    
    vector<vector<int> > ans ; 
    vector < int > tmp ; 
    
    for ( int i = 0 ; i < A.size() ; )
    {   
        for ( int j = i+1 ; j < A.size() ;  )
        {
            for ( int p = j+1 , q = A.size()-1 ; p < q ; )
            {   
                //cout<<i<<" "<<j<<" "<<p<<" "<<q<<endl ; 
                
                if ( A[p] + A[q] < B - A[i] - A[j] )
                {
                    for ( int x = p ; A[x] == A[p] and p < A.size() ; p++ ) ;  
                }
                else if (  A[p] + A[q] > B - A[i] - A[j]  )
                {
                    for ( int y = q ; A[y] == A[q] and q > j ; q-- ) ;  
                }
                else
                {   
                    //cout<<i<<" "<<j<<" "<<p<<" "<<q<<endl ; 
                    tmp = { A[i] , A[j] , A[p] , A[q] } ; 
                    ans.push_back(tmp) ; 
                    tmp.clear() ;
                    for ( int x = p ; A[x] == A[p] and p < A.size() ; p++ ) ;  
                    for ( int y = q ; A[y] == A[q] and q > j ; q-- ) ;  
                }
            }
            for ( int z = j ; A[z] == A[j] ; j++ ) ; 
        }
        for ( int w = i ; A[w] == A[i] ; i++ ) ; 
    }
    return ans ; 
}
