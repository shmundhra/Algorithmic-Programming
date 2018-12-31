// https://www.codechef.com//DEC17/problems/GIT01

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define rep(i,n) for(i=0;i<n;i++)

using namespace std;

int main() {
    
    int t , n , m ;
    int ro , re , go , ge ;
    int i , j ; 
    
    char A[100][100] ; 
    cin>>t ; 
    while(t--)
    {   
        cin>>(n) ; 
        cin>>(m) ;
        rep( i , n )
        {
            rep ( j , m )
            {
                cin>>A[i][j];
            }
        }
        
        ro = re = go = ge = 0 ; 
        rep ( i , n )
        {
            rep ( j , m )
            {
                if ( ( i+j ) % 2 ) 
                {
                    if ( A[i][j] == 'R')
                        ro++ ; 
                    else
                        go++ ; 
                        
                }
                else
                {
                    if ( A[i][j] == 'R')
                        re++ ; 
                    else
                        ge++ ;
                }
            }
        }
        
        cout<<min(5*ro+3*ge , 5*re+3*go)<<endl;
    
    }
    	
	return 0;
}
