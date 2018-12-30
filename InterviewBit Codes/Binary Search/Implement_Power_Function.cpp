// https://www.interviewbit.com/problems/implement-power-function/

#define ll long long 

int modexpCALC ( ll base , ll expo , ll modulo )
{  
   // NON NEGATIVE BASE AND POSITVE EXPONENT 
   base = base % modulo ;
   ll ans = base ? 1 : 0 ;

   while ( expo )
   {
       if ( expo&1 )
           ans = (ans * base) % modulo ;

       expo >>= 1 ;
       base = (base*base)% modulo  ;

   }

   return (int)ans ;
}

int modexp ( ll BASE , ll EXPO , ll modulo )
{  
   ll base = ( (BASE >= 0) ? BASE : -BASE) ; 
   ll expo = ( (EXPO >= 0) ? EXPO : -EXPO) ; 

   ll ans = modexpCALC( base , expo , modulo ) ; 

   if ( BASE < 0 && expo%2 == 1 )   // ODD POWER OF A NEGATIVE BASE will be NEGATIVE  
   {
        ans = ( modulo - ans ) % modulo ; 
   }

   if ( EXPO < 0 )                  // NEGATIVE EXPONENT , MODULO INVERSE PROCEDURE 
   {
        ans = modexpCALC ( ans , modulo - 2 , modulo ) ; 
   }
   return ans ; 
}




int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    return modexp ( (ll)x , (ll)n , (ll)d ) ; 
    
}
