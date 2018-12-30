// https://www.interviewbit.com/problems/hotel-reviews/

/*
vector<int> Solution::solve(string A, vector<string> &B) {
    
    //A.pop_back() ; //FOR CUSTOM INPUT ONLY 
    
    A.push_back('_') ; 
    vector < string > s ; 
    for ( int i = 0 , j = 0 ; i<=j and j < A.size() ; )
    {
        if ( A[j] == '_' )
        {
            s.push_back( string( A.begin()+i , A.begin() + j ) ) ; 
            j++ ; 
            i = j ; 
        }
        else
        {
            j++ ; 
        }
    }
    
    set <string> se ( s.begin() , s.end() ) ; 
    s.clear() ; 
    s.assign ( se.begin() , se.end() ) ;  
    
    //for ( int i = 0 ; i < s.size() ; i++ ) cout<<s[i]<<"**"; cout<<endl ;  
    
    map < string , int > m[(int)B.size()] ; 
    
    for ( int i = 0 ; i  < (int)B.size() ; i++ )
    {
        B[i].push_back('_') ; 
        for ( int j = 0 , k = 0 ; j <=k and k < B[i].size() ;  )
        {
            if ( B[i][k] == '_' )
            {
                string temp( B[i].begin() + j , B[i].begin() + k ) ;
                
                //cout<<temp<<" " ; 
                
                m[i][temp]++ ; 
                
                k++ ; 
                j = k ; 
            }
            else
            {
                k++ ; 
            }
        }
        //cout<<endl ; 
    }
    
    vector < pair < long , long > > v(B.size()); 
    
    for ( int i = 0 ; i < B.size() ; i++ )
    {   
        long count = 0 ; 
        for ( int j = 0 ; j < s.size() ; j++ )
        {
            if ( m[i].find( s[j] ) != m[i].end() )
            {
                count += m[i][ s[j] ]; 
            }
        }
        v[i] = make_pair( count , -i ) ; 
    }
    sort ( v.begin() , v.end() , greater< pair<long,long> >() ) ; 
    
    //for ( int i = 0 ; i < v.size() ; i++ ) cout<<v[i].first<<v[i].second<<"  " ; cout<<endl ;  
    
    vector < int > ans ; 
    for ( int i = 0 ; i < (int)v.size() ; i++ ) 
    {
        ans.push_back( -v[i].second ) ; 
    }
    
    return ans ; 
}
*/
/*
vector<int> Solution::solve(string A, vector<string> &B)
{   
    //A.pop_back() ; FOR CUSTOM INPUT
    
    vector < int > tmp ( 26 , -1 ) ; 
    
    vector < vector < int > >trie ; 
    vector < pair<int , bool>  > data ;  
    
    trie.push_back(tmp) ; 
    data.push_back(make_pair(0,false)) ; 
    
    A.push_back('_') ; 
    vector < string > s ; 
    for ( int i = 0 , j = 0 ; i<=j and j < A.size() ; )
    {
        if ( A[j] == '_' )
        {
            s.push_back( string( A.begin()+i , A.begin() + j ) ) ; 
            j++ ; 
            i = j ; 
        }
        else
        {
            j++ ; 
        }
    }
    
    set <string> se ( s.begin() , s.end() ) ; 
    s.clear() ; 
    s.assign ( se.begin() , se.end() ) ;  
    
    A.clear() ; 
    for ( int i = 0 ; i < s.size() ; i++ ) A = A + s[i] + "_" ; 
    
    int pos = 0 ; 
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        if ( A[i] == '_' ) 
        {   
            data[pos].second = true ; 
            pos = 0 ; 
            continue ; 
        }
        
        int index = A[i]-'a' ; 
        
        data[pos].first+=1 ; 
        
        if ( trie[pos][index] == -1 )
        {
            trie[pos][index] = trie.size() ; 
            trie.push_back(tmp) ; 
            data.push_back(make_pair(0,false)) ;
        }
        pos = trie[pos][index] ;
        
        
    }
   
   for ( int x = 0 ; x < trie.size() ; x++ )
   {
       cout<<data[x]<<" " ; 
       for ( int y = 0 ; y < 26 ; y++ ) cout<<trie[x][y]<<"$" ;
       cout<<endl ; 
   }
   
   
    vector < pair<int,int> > v ; 
    int i , j , k ;
    
    for ( i = 0 ; i < B.size() ; i++ )
    {
        B[i] += "_" ;
        int count = 0 ;
        
        string tmp ; 
        for ( j = 0 ; j < B[i].size() ; j++ )
        {
            if ( B[i][j] != '_' ) tmp += B[i][j] ; 
            else
            {
                int pos  = 0 ; 
                int flag = 0 ; 
                
                for ( k = 0 ; k < tmp.size() ; k++ ) 
                {   
                    int index = tmp[k] - 'a' ; 
                    
                    if ( trie[pos][index] == -1 )
                    {
                        flag = 1 ; 
                        break ; 
                    }
                    else
                    {
                        pos = trie[pos][index] ; 
                    }
                }
                if ( !flag )
                {   
                    //cout<<tmp<<"FOUND!! " ; 
                    if ( data[pos].second == true ) 
                    {   
                        //cout<<"PERFECT !" <<endl ; 
                        count++ ; 
                    }
                }
                tmp.clear() ; 
            }
            
        }
       
        v.push_back(make_pair(count,-i) ) ; 
    }
    sort ( v.begin() , v.end() , greater< pair<long,long> >() ) ;
    
    vector < int > ans ; 
    for ( int i = 0 ; i < (int)v.size() ; i++ ) 
    {
        //cout<<v[i].first<<" ";
        ans.push_back( -v[i].second ) ; 
    }
    
    return ans ; 
    
    
}
*/

int value ( char c )
{
    if ( c == '_' ) return 26 ; 
    
    return c-'a' ; 
}
vector<int> Solution::solve(string A, vector<string> &B)
{
    vector < int > tmp ( 27 , -1 ) ; 
    
    vector < vector < int > >trie ; 
    trie.push_back(tmp) ; 
    
    A.push_back('_') ; 
   
    int pos = 0 ; 
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        if ( i > 0 and A[i-1] == '_' ) pos = 0 ; 
        
        int index = value ( A[i] ) ; 
       
        if ( trie[pos][index] == -1 )
        {
            trie[pos][index] = trie.size() ; 
            trie.push_back(tmp) ; 
        }
        pos = trie[pos][index] ;
    }
   
    vector < pair<int,int> > v ; 
    int i , j , k ;
    
    for ( i = 0 ; i < B.size() ; i++ )
    {
        B[i] += "_" ;
        int count = 0 ;
        
        string tmp ; 
        for ( j = 0 ; j < B[i].size() ; j++ )
        {
            if ( B[i][j] != '_' ) tmp += B[i][j] ; 
            else
            {   
                tmp += '_' ; 
                
                int pos  = 0 ; 
                
                for ( k = 0 ; k < tmp.size() ; k++ ) 
                {   
                    int index = value( tmp[k] ) ; 
                    
                    if ( trie[pos][index] == -1 )
                    {
                        break ; 
                    }
                    else
                    {
                        pos = trie[pos][index] ; 
                    }
                }
                if ( k == tmp.size() )
                {   
                   count++ ; 
                }
                tmp.clear() ; 
            }
            
        }
       
        v.push_back(make_pair(count,-i) ) ; 
    }
    sort ( v.begin() , v.end() , greater< pair<long,long> >() ) ;
    
    vector < int > ans ; 
    for ( int i = 0 ; i < (int)v.size() ; i++ ) 
    {
        //cout<<v[i].first<<" ";
        ans.push_back( -v[i].second ) ; 
    }
    
    return ans ; 
}