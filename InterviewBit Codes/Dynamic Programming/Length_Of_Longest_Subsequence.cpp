// https://www.interviewbit.com/problems/length-of-longest-subsequence/

vector < int > LIS ( vector < int > &v )
{
    vector < int > arr ( v.size() , 0 ) ; 
    
    for ( int i = 0 ; i < v.size() ; i++ )
    {
        int len = 0 ; 
        for ( int j = i-1 ; j >= 0 ; j-- )
        {
            if ( v[j] < v[i] ) len = max ( len , arr[j] ) ; 
        }
        arr[i] = 1 + len ; 
    }
    return arr ; 
}


int Solution::longestSubsequenceLength(const vector<int> &A) {
    
    vector < int > a = A ; 
    
    vector < int > pref = LIS(a) ; 
    
    reverse ( a.begin() , a.end() ) ; 
    
    vector < int > suff = LIS(a) ;
    
    int large = 0 ; 
    for ( int i = 0 ; i < a.size() ; i++ ) 
    {
        large = max ( large , pref[i] + suff[ (int)a.size()-1-i ] - 1 ) ; 
    }
    return large ; 
}
