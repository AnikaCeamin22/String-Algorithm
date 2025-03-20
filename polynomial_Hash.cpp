#include<bits/stdc++.h>
using namespace std;

using ll =  long long int;
#define en  "\n"
const int M=1e9+11, b=137,N=1e5+9;
int pw[N];

void prec()
{
    pw[0]=1;
    for(int i=1; i<N; i++)
        pw[i]=1LL*pw[i-1]*b % M;

    return;
}

ll get_hash(string& s)
{
    ll hs=0;
    for(int i=0; i<s.size(); i++)
    {
        hs=hs+(1LL*pw[i]*s[i])%M;
        hs%=M;
    }
    return hs;
}

void Solve()
{
    string a,b;
    cin>>a>>b;
    prec();
    ll x=get_hash(a), y=get_hash(b);
    cout<<x<<"  "<<y<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T=1,t=0;
    //cin>>T;
    while(T--){
            t++;
           //cout<<"Case "<<t<<": ";
           Solve();
    }

    return 0;
}
