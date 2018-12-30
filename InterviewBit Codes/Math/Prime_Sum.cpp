// https://www.interviewbit.com/problems/prime-sum/

vector<int> Solution::primesum(int A) {
    
    vector < bool > isprime ( A+1 , true ) ; 
    isprime[0] = isprime[1] = false ; 
    
    
   /*vector < int > prime ; 
    vector < int > spf ( A+1 , -1 ) ; 
    
    for ( int i = 2 ; i <= A ; i++ )
    {
        if ( isprime[i] )
        {
            prime.push_back(i) ;
            spf[i] = i ; 
        }
        
        for ( int j = 0; prime[j] <= spf[i] && i*prime[j] <= A && j < prime.size() ; j++ )
        {
            isprime[ i*prime[j] ] = false ; 
            spf[i*prime[j]] = prime[j] ; 
        }
    }
    */
    
    for ( long long i = 2 ; i*i <= A ; i++ )
    {
        if ( isprime[i] )
        {
            for ( long long j = i*i ; j <= A ; j+=i )
            {
                isprime[j] = false ; 
            }
        }
    }
    
    for ( long long i = 0 ; i < isprime.size() ; i++ )
    {
        if ( isprime[i] && isprime[A-i] )
        {
            vector < int > ans = { i , A-i } ; 
            return ans ; 
        }
        
    }

}
