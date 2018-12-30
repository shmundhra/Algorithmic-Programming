// https://www.interviewbit.com/problems/length-of-last-word/

int Solution::lengthOfLastWord(const string A) {
    
    int count = 0 ; 
    int i ;
    for ( i = A.size()-1 ; i>=0 && A[i] == ' ' ; i-- ) ; 
    for ( ; i>=0 && A[i] != ' ' ; i-- ) count++ ;
    return count ;
}
