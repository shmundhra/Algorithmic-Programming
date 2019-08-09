void update ( vll &BIT , int index , int value )
{
	for ( int i = index ; i < BIT.size() ; i += i&(-i) )
	{
		BIT[i] = maxi ( BIT[i] , value ) ; 
	}
}

int query ( vll &BIT , int index )
{	
	int ans = 0 ; 
	for ( int i = index ; i > 0; i -= i&(-i) )
	{
		ans = maxi ( BIT[i] , ans ) ; 
	}
	return ans ; 
}

int LIS ( vector < ll > &v )
{
	set < ll > s ( all(v) ) ; 		
	vll aux ( all(s) ) ; 	
	vll A ( sz(v) ) ; 

	lp( i, sz(v) )
		A[i] = lower_bound( all(aux) , v[i] ) - aux.begin() + 1 ; 	

	vll BIT ( sz(s) + 1 , 0 ); 	 
    
	lp( i, sz(A) )
		update ( BIT , A[i] , query ( BIT , A[i]-1 ) + 1 ) ;    

	return query ( BIT , sz(s) ) ; 
}

int main ()
{
    ll n ; cin>>n ; inarr(n) ; cout<<LIS(v) ;     
    return 0 ; 
}