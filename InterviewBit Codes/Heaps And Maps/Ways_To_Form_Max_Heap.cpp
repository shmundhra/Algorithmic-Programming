// https://www.interviewbit.com/problems/ways-to-form-max-heap/

typedef vector < int > vi ; 
typedef vector < bool > vb ; 
/*
int calc ( vb hash , int ind , int num , long long &ans , vi &counter , vi &heap)
{   
    if ( ind > num )
    {
        ans = (ans + 1 )%1000000007 ; 
        //for ( int i = 1 ; i <= num ; i++ ) cout<<heap[i]<<" "; cout<<endl ; 
        return 0 ; 
    }
    
    int start = num ; 
    if ( ind > 1 ) start = heap[ind/2] ; 
    
    for ( int i = start ; i > counter[ind] ; i-- )
    {
        if ( hash[i] == false )
        {
            hash[i] = true ;
            heap[ind] = i ; 
            calc ( hash , ind+1 , num , ans , counter , heap ) ; 
            hash[i] = false ; 
        }
    }
}

int Solution::solve(int A) {
        
    int num = A ; 
    vi heap (A+1,0) ; 
    
    long long ans = 0 ; 
    long ht = (int)log2(A) ;
    vi counter( 1<<(ht+1) , 0 ) ; 
    
    for ( int i = A ; i > A/2 ; i-- ) counter[i] = 1 ; 
    
    for ( int i = A/2 ; i > 0 ; i-- ) counter[i] = counter[2*i] + counter[2*i+1] + 1  ;
    
    for ( int i = 1 ; i <= A ; i++  ) counter[i]-- ;
    
    vb hash ( A+1 , false ) ; 
    calc ( hash , 1 , A , ans , counter , heap ) ; 
    
    return ans ; 
}*/

#define MOD 1000000007 

long long calc ( int A , long dp[101] , long ncrt[101][101] , vi &counter , int index )
{   
    if ( index > (A-1)/2 ) return 1 ; 
    
    int left = counter[2*index] ; 
    int right = counter[2*index + 1] ; 
    
    if ( dp[left]  == 0 )
    {
        dp[left] = calc ( A , dp , ncrt , counter , 2*index ) ; 
    }
    
    if ( dp[right]  == 0 )
    {
        dp[right] = calc ( A , dp , ncrt , counter , 2*index+1 ) ; 
    }
    
    unsigned long long ans = ( dp[left]%MOD * dp[right]%MOD * ncrt[ left+right ][ left ] )%MOD ;
    
    return (long long)ans ; 
}


int Solution::solve(int A) {
    
    long ncrt [101][101] ; 
    long dp[101] = {0} ; 
    
    for ( int i = 0  ; i < 101 ; i++  )
        ncrt[i][0] = 1 ; 
       
    for ( int i = 0  ; i < 101 ; i++  )
        ncrt[i][i] = 1 ; 
    
    for ( int i = 0  ; i < 101 ; i++ ) 
        for ( int j = 1  ; j < i ; j++ )   
            ncrt[i][j] = ( ncrt[i-1][j] + ncrt[i-1][j-1] ) % MOD ;     
    
    long long ans = 0 ; 
    long ht = (int)log2(A) ;
    vi counter( 1<<(ht+1) , 0 ) ; 
    
    for ( int i = A ; i > A/2 ; i-- ) counter[i] = 1 ; 
    
    for ( int i = A/2 ; i > 0 ; i-- ) counter[i] = counter[2*i] + counter[2*i+1] + 1  ;
    
    ans = calc ( A , dp , ncrt , counter , 1 ) ; 
    
    return (int)ans ; 
}
