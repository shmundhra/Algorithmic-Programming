// https://www.interviewbit.com/problems/palindrome-partitioning/

int solve ( vector< vector<string> > &ans , string &A , vector<string> &aux  , int pos , int count)
{   
    int n = (int)A.size() ; 
    if ( pos == n )
    {
        ans.push_back( vector < string > (aux.begin() , aux.begin()+count ) ) ; 
        return 0 ; 
    }
    
    for ( int i = pos+1 ; i <= n ; i++ )
    {
        if ( equal( A.begin() + pos , A.begin() + pos + (i-pos)/2 , A.rbegin() + (n-i) ) )
        {
            aux[count] = string ( A.begin() + pos , A.begin() + i )  ; 
            solve ( ans , A , aux , i , count + 1 ) ; 
        }
    }
}
vector<vector<string> > Solution::partition(string A) {
    
    vector< vector<string> > ans ; 
    vector<string> aux( (int)A.size() , " ") ; 
    solve ( ans , A , aux , 0 , 0 ) ; 
    return ans ; 
}
