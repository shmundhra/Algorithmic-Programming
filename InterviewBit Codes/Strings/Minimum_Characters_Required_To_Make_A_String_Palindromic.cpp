// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

vector < int > FF ( string A )
{
   vector < int > LPB ( (int)A.size() , 0 ) ; 
   
   int i = 1 ; int len = 0 ;
   
   while(i < (int)A.size() ) // Len always holds the value of the previous LPB 
   {
        if ( A[i] == A[len])
        {   
            LPB[i++] = ++len ; 
        }
        else
        {   
            if ( len == 0 )
            {
                LPB[i++] = 0 ; 
            }
            else    // Apparently this can be put into loop too ?? We basically need to 
            {       // keep doing this till we get either A[i] == A[len] or len : 0 -> -1 
                len = LPB[len-1] ; 
            }
        }
   }
   return LPB ; 
}

int Solution::solve(string A) {
    
   string temp = A ; 
   reverse(temp.begin() , temp.end() ) ; 
   A = A + "%#$@&" + temp ;
   
   vector < int > LPB = FF( A ) ; 
   
   return ( temp.size()-LPB[LPB.size()-1] ) ; 
} 
