// https://www.interviewbit.com/problems/letter-phone/

int solve ( vector<string> &ans , vector<string> &s , string &A , string &aux , int pos )
{
    if ( pos == (int)A.size() )
    {
        ans.push_back(aux) ; 
        return 0; 
    }
    int ind = A[pos] - 48 ;
    
    for ( int i = 0 ; i < s[ind].size() ; i++ )
    {
        aux[pos] = s[ind][i] ; 
        solve ( ans , s , A , aux , pos+1 ) ; 
    }
}

vector<string> Solution::letterCombinations(string A) {
    
  vector< string >s={ "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"} ;  

  vector < string > ans ; 
  
  string aux ( (int)A.size() , ' ' ) ;
  
  solve ( ans , s , A , aux , 0 ) ; 
  
  return ans ; 
}
