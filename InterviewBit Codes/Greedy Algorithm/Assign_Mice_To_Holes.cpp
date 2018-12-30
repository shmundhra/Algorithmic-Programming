// https://www.interviewbit.com/problems/assign-mice-to-holes/

int Solution::mice(vector<int> &A, vector<int> &B) {
    
    if ( A.empty() ) return 0 ; 
    
    sort ( A.begin() , A.end() ) ; 
    sort ( B.begin() , B.end() ) ; 
    
    int tim = abs ( A.back()- B.back() ) ; 
    
    for ( int i = (int)A.size()-2 ; i >= 0 ; i-- )
    {
        tim = max ( tim , abs(A[i]-B[i]) ) ;     
    }
    return tim ;  
}
