int main () 
{   
    int n , m ; 
    int x , y ; 

    cin>>n>>m ;

    vector < vector < int > > adj ( n , vector < int >() ) ;      // int -> pair < int , int > in case of Weights 

    for ( int i = 0 ; i < m ; i++ )
    {
        cin>>x>>y ; 

        adj[x].push_back(y) ; 

        adj[y].push_back(x) ;       // Depends on Directed Undirected 
    }

    stack < int > DS ; 

    vector < int > visited  ( n ,  0 ) ; 
    vector < int > parent   ( n , -1 ) ; 
    vector < int > depth    ( n , -1 ) ;

    int source = 0 ;     
    visited[source] = 1 ; 
    depth[source] = 0 ; 
    DS.push(source);

    while ( !DS.empty() )                               
    {
        int current = DS.top() ; 
        DS.pop() ;
        
        for ( int j = 0 ; j < (int)adj[current].size() ; j++ )
        {
            int child = adj[current][j] ; 
            if ( visited[child] == 0 )
            {
                visited[child]  = 1 ; 
                parent[child]   = current ; 
                depth[child] = depth[current] + 1 ; 
                DS.push(child) ; 
            }
        }        
    }



    



/*  while ( !DS.empty() ) 
    {
        int current = DS.top() ; 
        
        if ( visited[current] == 1 ) // Queues se alag, here a node is marked visited only when it appears at the top of the stack.
        {                            // This is because if it was done like we do for BFS , we might get an incorrect Search Path 
            DS.pop() ;               // because a node which is accesible from a lower level node might actually also be accesible 
            continue ;               // from a node at a higher level , which is traversed first . Hence that node shall actually
        }                            // appear as the latter's child rather than the formers. Hence this is followed 
        visited[current] = 1 ; 

        int flag = 0 ; 
        for ( int j = 0 ; j < (int)adj[current].size() ; j++ )
        {
            int child = adj[current][j] ; 
            if ( visited[child] == 0 )  
            {
                flag = 1 ; 
                parent[child]   = current ; 
                depth[child] = depth[current] + 1 ;             
                DS.push(child) ; 
            }            
        }
        if ( flag == 0 )                                // This is done because if a node has not been yet visited, but all its 
        {                                               // children have been visited, it is as good as a leaf and we pop out and        
            DS.pop() ;                                  // progress up the tree-esque search path whenever we encounter leaves.     
        }        
    }
*/

    
}