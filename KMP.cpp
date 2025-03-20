#include<bits/stdc++.h>
using namespace std;

using ll =  long long int;
#define en  "\n"

void computeLPS(string& p, vector<int>& LPS, int m)
{
        int len=0,i=1;
        LPS[0]=0;
        while(i<m)
        {
            if(p[i]==p[len])
            {
                len++;
                LPS[i]=len;
                i++;
            }
            else
            {
                if(len!=0) len=LPS[len-1];
                else
                {
                    LPS[i]=0;
                    i++;
                }
            }
        }
        return;
}

vector<int> searchP(string& p, string& t)
{
        int n=t.size(), m=p.size();
        vector<int>ans, LPS(m,0);
        computeLPS(p, LPS, m);

        int i=0, j=0;
        while(i<n)
        {
            if(t[i]==p[j])
            {
                i++;
                j++;
            }

            if(j==m)
            {
                ans.push_back(i-j);
                j=LPS[j-1];
            }
            else if(t[i]!=p[j])
            {
                if(j!=0) j=LPS[j-1];
                else i++;
            }
        }

        return ans;
}

void Solve()
{
    string t,p;
    cin>>t>>p;
    vector<int> ans = searchP(p,t);
    for(int i=0;  i<ans.size(); i++) cout<<ans[i]<<" ";
    cout<<endl;
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
