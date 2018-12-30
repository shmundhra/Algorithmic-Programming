// https://www.interviewbit.com/problems/count-and-say/

string Solution::countAndSay(int A) {
    
    if ( A == 1 ) return "1" ; 
    if ( A == 2 ) return "11" ; 
    
    string prev = "11";
    string temp ;
    
    int i , j ; 
    for ( i = 3 ; i <= A ; i++ )
    {  
        //cout<<prev<<" " ; 
        j = 0 ; 
        while ( j < (int)prev.size() )
        {   
            
            int count = 0  ; 
            char c = prev[j] ; 
            while( j < (int)prev.size() && prev[j]==c )
            {
                count++ ; 
                j++ ; 
            }
            
            temp.push_back(count+'0') ; 
            temp.push_back(c) ; 
        }
        prev = temp  ; 
        temp.clear() ; 
    }
    return prev ; 
    
}
