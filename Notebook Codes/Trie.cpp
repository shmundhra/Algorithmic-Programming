vector < int > tmp ( 27 , -1 ) ;
vector < vector < int > > trie ;

trie.pb ( tmp ) ;  
lp ( i , n )
{
	int pos = 0 ; 
	lp ( j , sz( v[i]) )
	{
		int index = val ( v[i][j] ) ; 
		if ( trie[pos][index] == -1 )
		{
			trie[pos][index] = sz(trie); 
			trie.pb(tmp) ; 
		}
		pos = trie[pos][index] ; 
	}
}