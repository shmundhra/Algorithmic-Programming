// https://www.interviewbit.com/problems/subset/

/*bool compare ( string a , string b )
{
    for ( int i = 0 ; i < a.size() ; i++ )
    {
        if( a[i] != b[i] )
        {   
            int flag = 0 ; 
            if ( a[i] == '0' )
            {   
                for ( int j = i+1 ; j < a.size() ; j++ )
                {
                    if( a[j] != '0' )
                    {
                        flag = 1 ; break ;
                    }
                }
                return (!flag) ;
            }
            else
            {
                for ( int j = i+1 ; j < b.size() ; j++ )
                {
                    if( b[j] != '0' )
                    {
                        flag = 1 ; break ;
                    }
                }
                return flag ;
            }
        }
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    
    int n = A.size() ; 
    sort ( A.begin() , A.end() ) ; 
    vector<vector<int> > ans ; 
    vector < string > v ;
    
    for ( int i = 0 ; i < (1<<n) ; i++ )
    {
        string tmp ; 
        for ( int j = 0 ; j < n ; j++ )
        {
            if ( (i & (1<<j) ) ) tmp.push_back('1') ; 
            else tmp.push_back('0') ; 
        }
        reverse ( tmp.begin() , tmp.end() ) ; 
        v.push_back(tmp) ; 
    }
    
    sort(v.begin() , v.end() , compare ) ; 
    //for ( int p = 0 ; p < (1<<n) ; p++ ) cout<<v[p]<<endl ; 
    
    for ( int i = 0 ; i < (1<<n) ; i++ )
    {  
        vector<int> s ; 
        for ( int j = 0 ; j < n ; j++ )
        {
            if ( v[i][j] == '1') s.push_back( A[j] ) ; 
        }
        ans.push_back(s) ; 
    }
    return ans ; 
    
}*/

/*
vector < int > SubsetP ( string s , const vector <int> &A )
{
    vector<int> v ; 
    for ( int i = 0 ; i < (int)A.size() ; i++ )
    {
        if ( s[i] == '1') v.push_back( A[i] ) ; 
    }    
    return v ; 
}
int solve ( vector< vector<int> > &ans , vector <int> &A , string s , int level , int flag )
{
    if ( flag == 1 )
    {
        string tmp = s ;
        for ( int i = 0 ; i < level ; i++ )
            tmp += "0";
            
        ans.push_back( SubsetP(tmp , A) ) ; 
    }
    if ( level == 0 ) return 0 ; 
    
    solve( ans , A , s + "1" , level-1 , 1 ) ; 
    solve( ans , A , s + "0" , level-1 , 0 ) ; 
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    
    int n = (int)A.size() ; 
    sort ( A.begin() , A.end() ) ; 
    
    vector<vector<int> > ans ;
    
    solve( ans , A , "" , n , 1 ) ; 
    return ans ; 
}*/

int solve ( vector<vector<int> > &ans, vector<int> &A, vector<int> v, int ind  )
{
    ans.push_back(v) ; 
    //if ( ind >= A.size() ) return 0 ;     Optional really 
    
    for ( int i = ind ; i < (int)A.size() ; i++ )
    {
        v.push_back( A[i] ) ; 
        solve ( ans , A , v , i+1 ) ; 
        v.pop_back() ; 
        
        //for ( int j = i ; A[j]==A[i] ; i++ ) ;   //Duplicate wala jagah se maara maine
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    
    sort ( A.begin() , A.end() ) ;
    
    vector<vector<int> > ans ; 
    vector<int> aux ; 
    
    solve ( ans , A , aux , 0 ) ; 
    
    return ans ; 
}
