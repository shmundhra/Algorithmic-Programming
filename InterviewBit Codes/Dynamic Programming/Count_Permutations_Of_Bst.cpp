// https://www.interviewbit.com/problems/count-permutations-of-bst/

// Question can be thought of as having two parts 
// 1.) Given A find number of BST Structures of Height B 
// 2.) Given a Structure find number of permutations which would lead to it being formed
#define MOD 1000000007 
typedef long long ll ; 

int Solution::cntPermBST(int A, int B) {
    
    if ( B >= A ) return 0 ; 
    
    vector < vector < ll > > ncr ( A+1 , vector < ll > ( A+1 , 0 ) ) ; 

    for ( int i = 0 ; i < A+1 ; i++ ) ncr[i][i] = ncr[i][0] = 1  ;

    for ( int i = 1 ; i < A+1 ; i++ )
    {
        for ( int j = 1 ; j < i ; j++ )
        {
            ncr[i][j] = ( ncr[i-1][j] + ncr[i-1][j-1] ) % MOD ; 
        }
    } 
    /*
    vector < vector < ll > > dp ( A+1 , vector < ll > ( A+1 , 0 ) ) ; 
    dp[0][0] = 1 ; 
   
    
    for ( int i = 1 ; i <= A ; i++ )
    {
        for ( int j = 0 ; j < i ; j++ )
        {   
            int lt = j ; int rt = i-1-j ; 
            
            for ( int k = 1 ; k <= A ; k++ )
            {   
                for ( int l = 0 ; l < k-1 ; l++ )
                {
                    dp[i][k] += (ncr[i-1][j] * ( (dp[lt][l] * dp[rt][k-1])%MOD ) )%MOD ; 
                }
                
                dp[i][k] += (ncr[i-1][j] * ( (dp[lt][k-1] * dp[rt][k-1])%MOD ) )%MOD ; 
                
                for ( int r = 0 ; r < k-1 ; r++ )
                {
                    dp[i][k] += (ncr[i-1][j] * ( (dp[lt][k-1] * dp[rt][r])%MOD ) )%MOD ;  
                }
                dp[i][k] %= MOD ; 
                
                //cout<<"Num: "<<i<<" LT: "<<j<<" RT: "<<i-1-j<<" Ht: "<<k<<" -> "<<dp[i][k]<<endl ;
            }
        }
    }
    return dp[A][B+1] ; 
    */
    
    vector < vector < ll > > dp ( A+1 , vector < ll > ( A+1 , 0 ) ) ; 
    dp[0].assign(A+1,1);
    dp[1].assign(A+1,1); dp[1][0] = 0 ; 
    
    for ( int i = 2 ; i <= A ; i++ )
    {
        for ( int j = 0 ; j < i ; j++ )
        {   
            int lt = j ; int rt = i-1-j ; 
            
            for ( int k = 2 ; k <= A ; k++ )
            {  
                dp[i][k] += (ncr[i-1][j] * ( dp[lt][max(0,k-2)] * ( (dp[rt][k-1]-dp[rt][max(0,k-2)]+MOD)%MOD) ) %MOD )%MOD ;  
                
                dp[i][k] += (ncr[i-1][j] * ( ( ( (dp[lt][k-1]-dp[lt][max(0,k-2)]+MOD)%MOD ) * ( (dp[rt][k-1]-dp[rt][max(0,k-2)]+MOD)%MOD ) )%MOD ) )%MOD ; 
                
                dp[i][k] += (ncr[i-1][j] * ( dp[rt][max(0,k-2)] * ( (dp[lt][k-1]-dp[lt][max(0,k-2)]+MOD)%MOD) ) %MOD )%MOD ;  
                
                dp[i][k] %= MOD ; 
                
                //cout<<"Num: "<<i<<" LT: "<<j<<" RT: "<<i-1-j<<" Ht: "<<k<<" -> "<<dp[i][k]<<endl ;
            }
        }
        
        for ( int k = 1 ; k <= A ; k++ ) dp[i][k] = ( dp[i][k] + dp[i][k-1] ) %MOD ; 
    }
    return (int)((dp[A][B+1]-dp[A][B]+MOD)%MOD) ;
}
