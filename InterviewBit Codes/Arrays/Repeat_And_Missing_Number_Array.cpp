// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
    long long ds = 0 ; 
    long long dss = 0 ; 
   
    for ( long long i = 0 ; i < (long long)A.size() ; i++ )
    {
       ds += (long long)(i+1) - (long long)A[i] ; 
       dss += (long long)(i+1)*(i+1) - (long long)((long long)A[i])*((long long)A[i]) ; 
    }    
    
    long long a =  ( ( dss -  ds*ds ) / (2*ds) )  ; 
    long long b =  ds + a ;  
    
    vector < int > v ; 
    v.push_back((int)a) ; v.push_back((int)b) ; 
    
    return v ; 
}
