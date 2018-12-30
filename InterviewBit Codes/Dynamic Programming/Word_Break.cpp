// https://www.interviewbit.com/problems/word-break/

vector < int > dp ; 
unordered_map < string , int > M ; 

int solve ( string &A , int start )
{
    if ( dp[start] == -1 )
    {   
        dp[start] = 0 ; 
        
        int res ; 
        string tmp = "" ; 
        
        for ( int i = start  ; i < (int)A.size() ; i++ )
        {
            tmp += A[i] ; 
            if ( M.find(tmp) != M.end() )
            {
                res = solve ( A , i + 1 ) ; 
                if ( res == 1 ) 
                {
                   dp[start] = 1 ; 
                   break ; 
                }
            }
        }
        
    }
    return dp[start] ; 
}

int Solution::wordBreak(string A, vector<string> &B) {
    
    //A.pop_back() ; 
    
    dp.clear() ; 
    dp.assign( (int)A.size()+1 , -1 ) ; 
    dp[(int)A.size()] = 1 ; 
    
    M.clear() ; 
    for ( auto s : B ) M[s]++ ; 
    
    int ans = solve ( A , 0 ) ; 
    
    return ans ; 
    
}
