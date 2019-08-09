ll anc[110] ;
ll size[110];

void initialise ( ll n ){
  lp(i,n)
     anc[i] = i , size[i] = 1 ;  
}

ll root ( ll node ){
    while ( anc[node] != node ) {
         anc[node] = anc[ anc[node] ] ;
         node = anc[node] ;
    }
    return node ;
}

void join ( ll v1 , ll v2 )
{
    ll r1 = root ( v1 ) ,r2 = root ( v2 ) ;
    if ( size[r1] < size[r2] )
    {
        anc[r1] = anc[r2] , size[r2]+=size[r1] ;
    }
    else
    {
        swap(&r1,&r2) ;
        anc[r1] = anc[r2] , size[r2]+=size[r1] ;
    }
}