// https://www.interviewbit.com/problems/largest-number/

bool compare ( int a , int b )
{
    int diga , digb ; 
    diga = 0 ; digb = 0 ; 
    //cout<<"#"<<a<<"-"<<b<<"#"<<endl ; 
    
    int i ;
    
    i= a ; do { diga++ ; } while(i/=10) ; 
    i= b ; do { digb++ ; } while(i/=10) ; 
    
    unsigned long long int num1 , num2 ; 
    
    num1 = a * (unsigned long long)pow(10,digb) + b ;  // ab 
    num2 = b * (unsigned long long)pow(10,diga) + a ;  // ba
    //cout<<"#"<<num1<<"-"<<num2<<"#"<<endl ; 
    
    if ( num1 < num2 )
        return true ;    // Matlab a should come pehele in sorted string 
    else                // usse the way we are building up the string aasani hoga
        return false ; 
}
string Solution::largestNumber(const vector<int> &A) {
    
    vector < int > v ; 
    v.assign( A.begin() , A.end() ) ; 
    
    int flag = 0 ; 
    for ( int i = 0  ; i < v.size() ; i++ )
    {
        if ( v[i] != 0 ) 
        {
            flag = 1 ; 
            break ; 
        }
    }
    if ( flag == 0 )
    {
        string s = { '0' } ; 
        return s ; 
    }
    
    sort ( v.begin() , v.end() , compare ) ; 
    
    
    /*
    for ( int i = 0 ; i < v.size() ; i++ )
        cout<<v[i]<<" " ;
    cout<<endl ; 
    */
    
    
    string s ; 
    
    for ( int i = 0 ; i < v.size() ; i++ )
    {   
        long j = v[i] ; 
        do
        {
            s.push_back( j%10 + '0' ); 
            
        } while( j/=10 ) ; 
        
    }
    reverse ( s.begin() , s.end() ) ; 
    
    return s ; 
    
    
}
