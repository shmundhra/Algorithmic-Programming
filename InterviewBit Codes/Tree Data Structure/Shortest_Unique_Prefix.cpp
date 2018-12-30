// https://www.interviewbit.com/problems/shortest-unique-prefix/

/*struct trie 
{
    char s ; 
    int num ; 
    vector < trie* > arr ;
    
    trie (char x ): s(x) , num(1) , arr(vector< trie* >(26,NULL)) {} ; 
    
} ; 

trie* T ; 

vector<string> Solution::prefix(vector<string> &A) {
    
    T = new trie('$') ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        trie *it = T ; 
         
        //cout<<"\nInserting  "<<A[i]<<endl ; 
        
        for ( int j = 0 ; j < (int)A[i].size() ; j++ )
        {   
            
            
            if ( it->arr[ A[i][j] -'a' ] == NULL )
            {   
                //cout<<"Position ->"<<it->s<<endl ; ; 
                for ( ; j < (int)A[i].size() ; j++ )
                {   
                    //cout<<"Push"<<A[i][j]<<" " ; 
                    trie *N = new trie ( A[i][j] ) ; 
                    it->arr[ A[i][j] -'a' ] = N ; 
                    it = N ; 
                }
            }
            else
            {   
                //cout<<"Present->"<<(it->s)<<"  "; 
                it = it->arr[ A[i][j] -'a' ] ; 
                (it->num)+=1 ; 
            }
        }
    }
    
    vector < string > ans ; 
    
    for ( int i = 0 ; i < A.size() ; i++ ) 
    {
        trie* it = T ; 
        
        int j ; 
        string tmp ; 
        for ( j = 0 ; j < A[i].size() ; j++ )
        {
            it = it->arr[ A[i][j] -'a' ] ; 
            tmp += A[i][j] ; 
            if ( it->num == 1 ) break ; 
        }
        
        ans.push_back ( tmp ) ;    
    }
    
    return ans ; 
    
    
    
}*/


vector<string> Solution::prefix(vector<string> &A) {
    
   vector < vector < int > > trie ; // Trie will only hold the LINKAGES 
   vector < pair<int,bool> > data ; // All the required Data for THAT particular node 
   
   vector < int > tmp ( 26, -1 )  ; 
   trie.push_back(tmp) ;
   data.push_back( make_pair(0,false) ) ; 
   
   for ( int i = 0 ; i < A.size() ; i++ )
   {    
       int pos = 0 ; 
       for ( int j = 0 ; j < A[i].size() ; j++ )
       {    
           int index = A[i][j] -'a' ; 
           
           data[pos].first += 1 ; 
           
           if ( trie[pos][ index ] == -1 )
           {
                trie[pos][ index ] = trie.size() ; 
                trie.push_back(tmp) ; 
                data.push_back( make_pair(0,false) ) ;
           }
           
           pos = trie[pos][ index ] ; 
       }
       data[pos].second = true ; 
   }
   
   /*
   for ( int x = 0 ; x < trie.size() ; x++ )
   {
       cout<<data[x]<<" " ; 
       for ( int y = 0 ; y < 26 ; y++ )cout<<trie[x][y]<<" " ;
       cout<<endl ; 
   }
   */
   
   vector < string > ans ; 
   
   for ( int i = 0 ; i < A.size() ; i++ )
   {    
       int pos = 0 ; 
       string tmp ; 
       for ( int j = 0 ; j < A[i].size() ; j++ )
       {    
           tmp += A[i][j] ; 
           pos = trie[pos][ A[i][j]-'a' ] ;
           
           if ( data[pos].first <= 1 ) // Data[pos] counts after creation we traversed below it
           {
               break ; 
           }
            
       }
       ans.push_back(tmp) ; 
   }
    
    return ans ; 
}
