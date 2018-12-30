// https://www.interviewbit.com/problems/n3-repeat-number/

int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

   int num1 , num2 ; 
   int c1 , c2 ; 
   
   c1 = c2 = 0 ; 
   num1 = num2 = -1 ; 
   
   for ( int i = 0 ; i < A.size() ; i++ )
   {    
        if ( c1 == 0 )
        {   
            num1 = A[i] ; 
            c1++ ; 
            continue ; 
        }
        
        if ( c2 == 0 and A[i] != num1 )
        {
            num2 = A[i] ; 
            c2++ ;
            continue ; 
        }
        
        if ( A[i] == num1 )
        {
            c1++ ; 
        }
        else if ( A[i] == num2 )
        {
            c2++ ; 
            if ( c2 > c1 )
            {
                swap ( c1 , c2 ) ; 
                swap ( num1 , num2 ) ; 
            }
        }
        else 
        {
            c1 -- ; 
            c2 -- ; 
        }
        
    }
   
   c1 = c2 = 0 ; 
   
   for ( int i = 0 ; i < A.size() ; i++ )
   {
       if ( A[i] == num1 ) c1++ ; 
       else if ( A[i] == num2 ) c2++ ; 
   }
   if ( c1 > A.size()/3 ) return num1 ; 
   if ( c2 > A.size()/3 ) return num2 ; 
   return -1 ;  
   
   /*
    int cnt1=0, cnt2=0;
    int a,b;
    for(int n: A){
        if (n != b and (cnt1 == 0 || n == a) ){
            cnt1++;
            a = n;
        }
        else if (cnt2 == 0 || n==b){
            cnt2++;
            b = n;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1=cnt2=0;
    for(int n: A){
        if (n==a) cnt1++;
        else if (n==b) cnt2++;
    }
   if ( cnt1 > A.size()/3 ) return a ; 
   if ( cnt2 > A.size()/3 ) return b ; 
   return -1 ;*/
}
