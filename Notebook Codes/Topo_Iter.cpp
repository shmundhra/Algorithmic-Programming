priority_queue < int , vi , greater<int> > pq ; 
//queue < int > pq for normal TOPO SORT 
lp ( i , n ) {
    if ( in_deg[i] == 0 ) {
        pq.push(i) ; 
    }
}

while ( !pq.empty() )
{
    int source = pq.top() ;
    topo_sort.pb(source+1) ; 
    pq.pop() ; 

    lp ( j , (int)adj[source].size() )
    {
        int nbr = adj[source][j] ; 
        in_deg[nbr] -- ; 

        if ( in_deg[nbr] == 0 ) {
            pq.push(nbr) ; 
        }
    }
}