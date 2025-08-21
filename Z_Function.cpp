#include<bits/stdc++.h>
using namespace std;

using ll = long long int;
#define en  "\n"

// Z Function=longest substring starting at i which is also prefix of the string
// https://www.youtube.com/watch?v=6mzNnEGimPA
// https://www.youtube.com/watch?v=USn1aRaKnJo&list=PLl4Y2XuUavmuEzOKhnLQIRTtI2SMtWini&index=7
// https://cp-algorithms.com/string/z-function.html

vector<int>Z_function(string s)
{
    int n=s.size();
    vector<int>z(n);
    int l=0,r=0;
    for(int i=1; i<n; i++)
    {
        if(i<r)   // i between l and r
            z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) // random checking
            z[i]++;
        if(z[i]+i-1>r) // set new right most substring
        {
            l=i;
            r=z[i]+i-1;
        }
    }
    return z;
}

void Solve()
{
    string s;
    cin>>s;
    vector<int>z1=Z_function(s);
   for(int i=0; i<(int)s.size(); i++) cout<<z[i]<<" ";
   cout<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int T=1,t=0;
     cin>>T;
    while(T--){
            t++;
   // cout<<"Case "<<t<<": ";
        Solve();
    }

    return 0;
}


