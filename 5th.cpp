/*
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod=1e9+7;
#define eps 1e-7
#define vpi vector<pair<int,int>>
#define vi vector<int>
#define pi pair<int,int>
#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define vvi vector<vector<int>>
ll powmod(ll x,ll y){ll t; for(t=1;y;y>>=1,x=x*x%mod) if(y&1) t=t*x%mod; return t;}
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
void smask(int pos,int &i){ i=i^(1<<pos); }
void clmask(int pos,int &i){ i=i&~(1<<pos); }
bool chmask(int pos,int i){return i&(1<<pos);}
double cordist(pair<double,double> a,pair<double,double> b)
{return sqrt(((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second)));}



//ll dp[60];
//int posx[10];
//int posy[10];
//int price[30];
//int dx[]={-1,0,1,0};
//int dy[]={0,1,0,-1};
//char board[26][26];

int n,m,q,r;
vector<vi> edges;
vector<ll> res;

ll costs(int a)
{
    if(res[a]!=-1)return res[a];
    ll t=0;
    for(int i=0;i<edges[a].size();i++)
        t+=costs(edges[a][i]);
    return res[a]=t;
}

void solve()
{
    bool flag=false;
    while(cin>>n)
    {
        if(flag)cout<<endl;
        flag=true;
        edges.clear();
        edges.resize(n);
        res.clear();
        res.resize(n,-1);
        for(int i=0;i<n;i++)
        {
            cin>>q;
            if(q==0)res[i]=1;
            for(int j=0;j<q;j++)
            {
                cin>>r;
                edges[i].pb(r);
            }
        }
        costs(0);
        cout<<res[0]<<endl;
    }


}
    


int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int k=1;
    //cin>>k;
    while(k--)
    {
        solve();  
    }
    return 0;
}
