// https://www.interviewbit.com/problems/longest-substring-without-repeat/

int Solution::lengthOfLongestSubstring(string A) {

    vector < bool > hash ( 256 , false ) ; 
    
    int count = 0 ; 
    int maxcount = 0 ; 
    
    for ( int l = 0 , r = 0 ; l < A.size() and r < A.size() ; )
    {
        if ( hash [ A[r] ] == false )
        {
             hash [ A[r] ] = true ;  
             count++ ;
             maxcount = max ( maxcount , count ) ; 
             r++ ; 
        }
        else
        {
            hash [ A[l] ] = false ; 
            l++ ; 
            count-- ; 
        }
    }
    return maxcount ; 
    
}
