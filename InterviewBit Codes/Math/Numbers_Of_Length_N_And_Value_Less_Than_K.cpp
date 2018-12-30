// https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/

int Solution::solve(vector<int> &A, int B, int C) {

   if ( C == 0 ) return 0 ; 
   if ( A.size() == 0 ) return 0 ; 
   if ( B == 1 ) return ( lower_bound(A.begin() , A.end() , C ) - A.begin() ) ;  
   
   vector <int> hash ( 10 , 0 ) ; 
   for ( int i = 0 ;  i < A.size() ; i++ ) 
        hash[A[i]] = 1 ; 
   
   vector < int > count ( 10 , 0 ) ;  // Number of elements less than i store hoyega
   for ( int i = 1 ; i < 10 ; i++ )
   {
       count[i] = hash[i-1]+count[i-1] ; 
       
   }   
   
   vector < long long > power ; 
   power.push_back(1) ; 
   for ( int i = 1 ; i < B ; i++)
   {
       power.push_back ( power[i-1]*A.size() ) ; 
      
   }      
   
   vector < int > num ; 
   for ( int i = C ; i > 0 ; i/=10 ) 
   {
       num.push_back(i%10) ; 
   }
   reverse( num.begin() , num.end() ) ; 

   long long ans = 0 ; 
   if ( num.size() < B ) return 0 ; 
   
   if ( num.size() > B ) 
   {    
      ans = power[B-1] ; 
      
      if  ( A[0] == 0 ) 
        ans *= ( A.size() - 1 ) ; 
      else 
        ans *= A.size() ; 
      
      return ans ; 
   }
   
   for ( int i = 0 ; i < num.size() ; i++ )
   {
       int id = count[ num[i] ] ; 
       
       if ( (i == 0) && ( hash[0]==1 ) ) 
       {
           id--  ; 
       }
       ans += ( id * power[B-1-i ] ) ; 
       
       if ( hash[ num[i] ] == 0 ) return ans ; 
   }
   return ans ;
   
   
}
