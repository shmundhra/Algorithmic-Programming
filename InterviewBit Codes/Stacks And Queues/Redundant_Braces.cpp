// https://www.interviewbit.com/problems/redundant-braces/

int Solution::braces(string A) {

    stack < char > s ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        if ( A[i] != ')' ) s.push(A[i]) ; 
        
        else
        {
            int flag = 0 ; 
            while ( s.top() != '(' )
            {
                if ( s.top() == '+' or s.top() == '-' or s.top() == '*' or s.top() == '/' )
                {
                    flag = 1 ; 
                }
                s.pop() ; 
            }
            s.pop() ; 
            if ( flag == 1 ) continue ; 
            else return 1 ; 
        }
    }
    return 0 ; 
    
}
