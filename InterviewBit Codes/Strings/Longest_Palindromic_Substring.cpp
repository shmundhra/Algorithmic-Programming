// https://www.interviewbit.com/problems/longest-palindromic-substring/

/*vector < int > FF ( string s )
{
    vector < int > LPB ( s.size() , 0 ) ; 
   
    int i = 1 ; 
    int len = 0 ; 
    
    while ( i < s.size() )
    {
        if ( s[i] == s[len] )
        {
            LPB[i++] = ++len ; 
        }
        else
        {
            if ( len == 0 )
            {
                i++   ;       // LPB[i++] = 0 but woh pehele se waise hi assigned hai
            }
            else
            {
                len = LPB[len-1] ; 
            }
        }
    }
    return LPB ; 
}

int palin ( string A  , int start )
{
    string s ( A.begin() + start , A.end() ) ; 
    
    s = s + "#$%&@" + string ( s.rbegin() , s.rend() ) ;  
    
    vector < int > LPB = FF ( s ) ; 
    
    return LPB[LPB.size()-1] ; 
}

string Solution::longestPalindrome(string A) {
    
    int maxl = 1 ; 
    int maxp = 0 ; 
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        if ( maxl < palin(A,i) )
        {
            maxl = palin(A,i) ; 
            maxp = i ; 
        }
    }
    string ans ( A.begin() + maxp , A.begin() + maxp + maxl ) ; 
    
    return ans ; 
    
}*/

/*
string Solution::longestPalindrome(string A)
{
    vector < int > a ( A.size() , 0 ) ; 
    vector < vector < int > > Arr ( A.size() , a ); 
    
    int start , end ; 
    start = end = 0 ; 
    
    for ( int k = A.size() - 2 ; k >= 0  ; k-- )
    {
        for ( int i = k , j = A.size()-1 ; i >= 0 ; i-- , j-- )
        {
            if (  !( Arr[i][j] = Arr[i+1][j-1] + (A[i]!=A[j]) )  )
            {
                start = i ; 
                end = j ; 
            }
        }
    }
    
    return string(A.begin()+start , A.begin()+end+1) ; 
}*/

string Solution::longestPalindrome(string A)
{
    vector < int > Arr ( 2*A.size() , 0 ) ; 
    
    int start , end ; 
    start = end = 0 ; 
    
    for ( int k = A.size() - 2 ; k >= 0  ; k-- )
    {
        for ( int i = k , j = A.size()-1 ; i >= 0 ; i-- , j-- )
        {
            if (  !( Arr[i+j] = Arr[i+j] + (A[i]!=A[j]) )  )
            {
                start = i ; 
                end = j ; 
            }
        }
    }
    
    return string(A.begin()+start , A.begin()+end+1) ; 
}
