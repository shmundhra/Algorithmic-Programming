// https://www.interviewbit.com/problems/palindrome-string/

int Solution::isPalindrome(string A) {
    
    transform ( A.begin() , A.end() , A.begin() , ::tolower ) ; 
    int i , j ; 
    for ( i = 0 , j = A.size()-1 ; i <= j ; i++ , j-- )
    {
        while( (i < j) && (isalnum(A[i]) == false) ) i++ ; 
        while( (j > i) && (isalnum(A[j]) == false) ) j-- ; 
        
        if ( (A[i] != A[j]) ) return 0 ; 
    }
    return 1 ; 
}
