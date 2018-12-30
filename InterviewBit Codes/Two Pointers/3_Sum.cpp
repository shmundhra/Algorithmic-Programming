// https://www.interviewbit.com/problems/3-sum/

long abso ( long a , long b )
{
    if ( a > b ) 
        return a - b ; 
    else 
        return b - a ; 
}

int Solution::threeSumClosest(vector<int> &A, int B) {
/*
   if ( A.size() < 3 ) return 1000000000 ; 
   sort(A.begin() , A.end() ) ; 
   
   //for ( int i = 0 ; i < A.size() ; i++ ) cout<<A[i]<<" " ; cout<<endl ; 
   
   int i = -1 ;
   int j = 1 ; 
   int k = A.size() - 1 ; 
   
   long lsum = INT_MIN ; 
   long rsum = INT_MAX ; 
   while ( i < k-1 )
   {    
       i = i + 1 ; 
       j = i + 1 ; 
       
       while ( j < k )
       {    
           //cout<<i<<" "<<j<<" "<<k<<endl ; 
           
           long sum = A[i] + A[j] + A[k] ; 
           if ( sum == B) return B ; 
           
           if ( sum >  B )
           {
               if ( sum < rsum ) rsum = sum ;     
               k-- ; 
           }
           else
           {    
               if ( sum > lsum ) lsum = sum ; 
               if ( j-i == 1 ) 
               {
                   j++ ; 
               }
               else
               {
                   if ( A[i+1] + A[j] <= A[i] + A[j+1] ) 
                        i++ ; 
                   else 
                        j++ ;
               }
           }
       }
   }   
   if ( (long)(B - lsum) <= (long)(rsum - B) )
       return (int)lsum ; 
   else
       return (int)rsum ; 
    */   
       
    long mini = 1000000000 ; 
    
    int i , j , k ; 
    
    for ( i = 0 ; i < (int)A.size()-2 ; i++ )
    {
        
        for ( j = i+1 , k = (int)A.size()-1 ; j < k  ; )
        {
            int sum = A[i] + A[j] + A[k] ; 
            cout<<i<<" "<<j<<" "<<k<<endl ; 
            
            if ( sum == B ) return B ; 
            
            if ( abso( mini , (long)B) > abso(sum , (long)B) )
                mini = sum ; 
            
            if ( sum > B ) k-- ; 
            else j++ ; 
        }
    }
    return (int)mini ; 
    
}
