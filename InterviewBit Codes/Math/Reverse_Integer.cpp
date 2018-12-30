// https://www.interviewbit.com/problems/reverse-integer/

int Solution::reverse(int A) {
    
    long long B = 0 ; 
    long long C = (A<0) ? -A : A ;  
    //cout<<"*"<<C ;
    for ( long long i = C ; i > 0 ; i/= 10 )
    {
        B*=10 ; 
        B+=i%10 ; 
        //cout<<"**"<<B<<"*"<<i ; 
    }
    //cout<<endl ; 
    if ( B >= ( long long )pow(2,31) ) return 0 ; 
    
    B = (A<0) ? -B : B ;
    return B ; 
}
