// https://www.interviewbit.com/problems/anagrams/

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    
    unordered_map < string , vector < int > > m ; 
    vector<vector<int> > ans ;
    vector < string > v ( A.begin() , A.end() ) ; 
    
    for ( int i = 0 ; i < v.size() ; i++ ) sort ( v[i].begin() , v[i].end() ) ; 
    
    for ( int i = 0 ; i < v.size() ; i++ )  m [ v[i] ].push_back(i+1) ; 
    
    for ( auto it = m.begin() ; it != m.end() ; it++ )  ans.push_back(it->second) ; 
    
    sort(ans.begin() , ans.end() ) ; 
    
    return ans ; 
}
