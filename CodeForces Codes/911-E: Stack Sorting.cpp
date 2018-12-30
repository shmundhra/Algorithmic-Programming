//https://codeforces.com/contest/911/problem/E

#include <bits/stdc++.h>
using namespace std;

int main() 
{   
    int n , k ; 
    cin>>n>>k ; 
    vector<int> v ;      
    
    int temp ; 
    for ( int i = 0 ; i < k ; i++ )
    {
        cin>>temp ;
        v.push_back(temp) ;               
    }

    int count = 1 ; 

    stack < int > s ; 
    for ( int i = 0 ; i < k ; i++ )
    {
        if( s.empty() ) s.push( v[i] ) ; 
        else
        {
            while ( !s.empty() and s.top() < v[i] )
            {
                if ( s.top() == count )
                {
                    s.pop() ; 
                    count++ ; 
                }
                else
                {
                    count = -1 ; 
                    break ; 
                }
            }
            if ( count == -1 ) break ; 
            s.push( v[i] ) ; 
        }
    }
    if ( count == -1 ) cout<<-1<<endl ; 
    else
    {   
        while( !s.empty() )
        {
            int start = s.top()-1 ;             
            for ( int i = start ; i >= count ; i-- )
                v.push_back(i) ;         
            count = s.top()+1 ; 
            s.pop() ; 
        }
        for ( int i = n ; i >= count ; i-- )
                v.push_back(i) ;

        for ( int i = 0 ; i  < n ; i++ )cout<<v[i]<<" "; cout<<endl ; 
    }    
}