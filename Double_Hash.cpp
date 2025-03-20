#include<bits/stdc++.h>
using namespace std;

using ll =  long long int;
#define en  "\n"
const int M1=1e9+11, b1=137,N=1e5+9, M2=1e9+9, b2=277;
int pw1[N], pw2[N];

void prec()
{
    pw1[0]=1;
    for(int i=1; i<N; i++)  pw1[i]=1LL*pw1[i-1]*b1 % M1;

    pw2[0]=1;
    for(int i=1; i<N; i++) pw2[i]=1LL*pw2[i-1]*b2 % M2;

    return;
}

pair<int,int> get_hash(string& s)
{
    int hs1=0;
    for(int i=0; i<s.size(); i++)
    {
        hs1=hs1+(1LL*pw1[i]*s[i])%M1;
        hs1%=M1;
    }

    int hs2=0;
    for(int i=0; i<s.size(); i++)
    {
        hs2=hs2+(1LL*pw2[i]*s[i])%M2;
        hs2%=M2;
    }
    return {hs1,hs2};
}

void Solve()
{
    string a,b;
    cin>>a>>b;
    prec();
    pair<int,int>x,y;
    x=get_hash(a);
    y=get_hash(b);
    cout<<x.first<<" "<<x.second<<endl;
    cout<<y.first<<" "<<y.second<<endl;
    cout<<(x==y)<<endl;
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

