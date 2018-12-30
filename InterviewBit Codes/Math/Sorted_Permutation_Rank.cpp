// https://www.interviewbit.com/problems/sorted-permutation-rank/

#define MOD 1000003 

int index ( char c ) 
{
    if ( isupper(c) )
    {
        return ( c - 'A' + 1 ) ; 
    }
    else
    {
        return ( c - 'a' + 1 + 26 ) ; 
    }
}

long long fact ( int n )
{
    long long ans = 1 ; 
    while(n) {
        
        ans = ( (ans%MOD) * (n%MOD ) ) % MOD ; 
        n-- ; 
    }
    
    return (ans%MOD) ; 
}

vector < int > BIT ( 500 , 0 ) ;  

void update(int x, int delta)
{
      for(  ; x <= 52 ; x += x&-x )
        BIT[x] += delta;
}

int query(int x)
{
     int sum = 0;
     
     for(  ; x > 0 ; x -= x&-x )
        sum += BIT[x];
     return sum;
}



int Solution::findRank(string A) {
    
    for ( int i = 0 ;  i < A.size() ; i++ )
    {   
         update ( index(A[i]) , 1 ) ; 
    }
    
    long long count = 1 ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        int ind = query( index(A[i]-1) )  ; // COZ ELEMENT ko include nahi karna hai !!
        
        //cout<<ind<<"#" ;
        
        count += (ind) * ( ( fact(A.size()-1 -i) ) % MOD )  ; 
        count %= MOD ; 
        
        //cout<<count<<endl;
        
        update ( index(A[i]) , -1 ) ; 
    }
    return count ; 
}
