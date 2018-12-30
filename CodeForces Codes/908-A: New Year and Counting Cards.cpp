//https://codeforces.com/contest/908/problem/A

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
using namespace std; 

typedef unsigned long long ul ;
typedef long long ll ;

typedef pair<ll, ll>  pll ;
typedef pair< ll , pll > edge ; 
typedef vector < ll > uwg ;
typedef vector < pll > wg ;

#define scu(x) ul x ; scanf("%llu", &x)  
#define scl(x) ll x ; scanf("%lld", &x)  
#define pr(x) printf("%llu", x)  
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define f first 
#define s second
#define pb push_back
#define mp make_pair
#define tc(t) scu(t); while ( t-- )


int main() {
	
	string s ; 
	cin>>s;
	int c = 0 ;  
	rep ( i , 0 , s.size() , 1 )
	{
	    if ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] =='u' ) 
	        c++ ; 
	    if ( s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] =='9' )
	        c++ ; 
	}
	cout<<c<<endl;
	
	return 0;
}
















