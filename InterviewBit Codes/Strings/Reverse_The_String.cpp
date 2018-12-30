// https://www.interviewbit.com/problems/reverse-the-string/

void Solution::reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    /*
    int i = A.size() - 1 ; 
    string rev ; 
    while ( i >= 0 )
    {
        for ( ; i>=0 && A[i] == ' ' ; i-- )
        {
            rev.push_back(A[i]) ; 
        }
        string temp ; 
        for ( ; i >=0 && A[i] != ' ' ; i-- )
        {
            temp.push_back(A[i]) ; 
        }
        reverse( temp.begin() , temp.end() ) ; 
        for ( int j = 0 ; j < temp.size() ; j++ )
        {
            rev.push_back(A[j]) ; 
        }
    }*/
    
    int i = (int)A.size() - 1 ; 
    string rev ; 
    while ( i >= 0 )
    {
        for ( ; i >=0 && A[i] == ' ' ; i-- ) ; 
        
        string temp ; 
        for ( ; i >=0 && A[i] != ' ' ; i-- )
        {
            temp.push_back(A[i]) ; 
        }
        reverse( temp.begin() , temp.end() ) ; 
        rev.append(temp) ; 
        /*for ( int j = 0 ; j < (int)temp.size() ; j++ )
        {
            rev.push_back(temp[j]) ; 
        }*/
        rev.push_back(' ') ; 
    }
    rev.pop_back() ; 
    A = rev ; 
    
}
