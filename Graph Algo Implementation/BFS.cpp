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

    queue < int > DS ; 

    vector < int > visited  ( n ,  0 ) ; 
    vector < int > parent   ( n , -1 ) ; 
    vector < int > distance ( n , -1 ) ;

    int source = 0 ; 
    visited[source] = 1 ; 
    distance[source] = 0 ; 
    DS.push(source); 

    while ( !DS.empty() ) 
    {
        int current = DS.front() ; 
        DS.pop() ;
        
        for ( int j = 0 ; j < (int)adj[current].size() ; j++ )
        {
            int child = adj[current][j] ; 
            if ( visited[child] == 0 )
            {
                visited[child]  = 1 ; 
                parent[child]   = current ; 
                distance[child] = distance[current] + 1 ; 
                DS.push(child) ; 
            }
        }        
    }






    
}