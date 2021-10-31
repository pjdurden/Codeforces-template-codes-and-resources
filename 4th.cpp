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


int dx[]={-1,1,0,0};//N,S,E,W
int dy[]={0,0,-1,1};

int n,m,q,r;
bool arr[51][51];
int dist[55][55][5];
bool vis[55][55][5];

bool isvalid(int x,int y)
{
    return ( x>0 and y>0 and x<n and y<m and !arr[x][y-1] and !arr[x-1][y]
            and !arr[x-1][y-1] and !arr[x][y] );
}

int bfs(int i,int j,int dir,int k,int l)
{
    memset(dist,-1,sizeof(dist));
    memset(vis,false,sizeof(vis));
    queue<pair<pi,int>>q;
    dist[i][j][dir]=0;
    vis[i][j][dir]=true;
    
    if(isvalid(i,j))q.push({{i,j},dir});
    while(!q.empty())
    {
        int tx=q.front().first.first;
        int ty=q.front().first.second;
        int tdir=q.front().second;
        q.pop();
        printf("%d %d %d\n",tx,ty,tdir);
        if(tx==k and ty==l)
            return dist[k][l][tdir];

        int dir1,dir2;
        if(tdir==0 or tdir==1){dir1=2;dir2=3;}
        else {dir1=0;dir2=1;}
        if(!vis[tx][ty][dir1] )
        {
            vis[tx][ty][dir1]=true;    
            dist[tx][ty][dir1]=dist[tx][ty][tdir]+1;
            q.push({{tx,ty},dir1});
        }
        if(!vis[tx][ty][dir2] )
        {
            vis[tx][ty][dir2]=true;
            dist[tx][ty][dir2]=dist[tx][ty][tdir]+1;
            q.push({{tx,ty},dir2});
        }

        for(int i=1;i<=3;i++)
        {
            int ax=tx+((dx[tdir])*i);
            int ay=tx+((dy[tdir])*i);
            if(isvalid(ax,ay)) 
            {
                if(!vis[ax][ay][tdir] )
                {
                    vis[ax][ay][tdir]=true;
                    dist[ax][ay][tdir]=dist[tx][ty][tdir]+1;
                    q.push({{ax,ay},tdir});
                }
            }
            else break;
        }
        
        
    }
    return -1;
}


void solve()
{
    while(cin>>n>>m and !(n==0 and m==0))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
            }
        }

        int a,b,c,d;string k;
        cin>>a>>b>>c>>d>>k;
        int dir;
        if(k=="north")dir=0;
        else if(k=="south")dir=1;
        else if(k=="east")dir=2;
        else dir=3;
        cout<<bfs(a,b,dir,c,d)<<endl;
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
    //cin>>k;int counter=1;
    while(k--)
    {
        solve();
        
    }
    return 0;
}
