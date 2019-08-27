// https://www.codechef.com/KOL18ROLproblems/BUCKETWA

#include<bits/stdc++.h>
#define vi vector<int>
#define pp pair<int,int>
#define all(x) x.begin(),x.end()
#define pb push_back
#define forx(i,x) for(int i=0;i<x;i++)
#define disp(x) for(auto &y:x) cout<<y<<" "
//#define int long long

using namespace std;
double dh,dl,dr,k;
double calcval(double x)
{
    double term1 = sqrt(dh*dh+x*x);
    double term2 = sqrt(dl*dl+(dr-x)*(dr-x))*k;
    return (term1+term2);
}
double calcval2(double x)
{
    double term1 = sqrt(dh*dh+x*x);
    double term2 = sqrt(dl*dl+(dr-x)*(dr-x));
    return(term1+term2);
}
int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    double eps = 1e-4;
    while(1)
    {
    
    
    cin>>dh>>dl>>dr>>k;
    if(dh+dl+dr+k==0) break;
    double lo=0,hi=dr,mid;//distance from dh
        while(hi-lo>eps)
        {
            mid = (lo+hi)/2;
            double mid2 = mid+eps;
            double f1 = calcval(mid);
            double f2 = calcval(mid2);
            if(f2<f1)
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }
        if(calcval(0)<calcval(lo)) lo =0;
        if(calcval(dr)<calcval(lo)) lo =dr;
        //cout<<"lo is "<<lo<<endl;
        //cout<<calcval(lo)<<endl;
        cout<<fixed<<setprecision(10)<<calcval2(lo)<<endl;
    //  cout<<calcval(0)<<endl;
    //double f0 = 
    
    }   
    
    


}

