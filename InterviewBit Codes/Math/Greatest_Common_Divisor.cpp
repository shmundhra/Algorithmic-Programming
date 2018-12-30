// https://www.interviewbit.com/problems/greatest-common-divisor/

int Solution::gcd(int A, int B) {
    
    long long temp ; 
    long long C = max ( A , B ) ; 
    long long D = min ( A , B ) ; 
    
    while ( D )
    {
        temp = C%D ; 
        C = D ; 
        D = temp ;
    } 
    
    return C ; 
}
