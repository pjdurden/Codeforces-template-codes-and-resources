4 directional
int dx[]={-1,1,0,0};//N,S,w,E
int dy[]={0,0,-1,1};

8 directional/king move
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};

knight moves
int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};

3d 6directional move
int dx[]={0,0,1,-1,0,0};
int dy[]={0,0,0,0,1,-1};
int dz[]={1,-1,0,0,0,0};


grid dfs
//sol=0 for counting size of connected components
void solution(int x,int y)
{

    if(x<0 or y<0 or x>=n or y>=m or vis[x][y] or board[x][y]=='.')return;
    vis[x][y]=true;
    //if(board[x][y]==('x' or whatever))sol++;
    for(int i=0;i<4;i++)
    {
        int xt=x+dx[i];
        int yt=y+dy[i];
        solution(xt,yt);
    }
    return;
}

grid bfs
int bfs(int i,int j,int k,int l)
{
    memset(dist,-1,sizeof(dist));
    queue<pi>q;
    dist[i][j]=0;
    vis[i][j]=true;
    q.push({i,j});
    while(!q.empty())
    {
        pi a=q.front();
        q.pop();
        if(a.first==k and a.second==l)
            return dist[k][l];
        for(int i=0;i<4;i++)
        {
            int x=a.first+dx[i];
            int y=a.second+dy[i];
            if(x<0 or y<0 or x>=n or y>=m or vis[x][y]==true or dist[x][y]!=-1)continue;
            vis[x][y]=true;
            dist[x][y]=dist[a.first][a.second]+1;
            q.push({x,y});
        }
    }
    return -1;
}

adjacency list dfs
vector<int>edges[n];
void dfs(int node)
{

    if(vis[node])return;
    vis[node]=true;
    for(int i=0;i<edges[node].size();i++)
    {
        dfs(edges[node][i]);
    }
    return;
}

adjaceny list bfs
int bfs(int node,int dsc)
{
    dist.assign(n,-1);
    queue<int>q;
    q.push(node);
    dist[node]=0;
    vector<bool> vis(n,false);
    vis[node]=true;
    while(!q.empty())
    {
        int a=q.front();
        q.pop(); 
        if(a==dsc)return dist[a];
        for(int i=0;i<edges[a].size();i++)
        {
            if( dist[edges[a][i]]==-1 or !vis[edges[a][i]] )
            {
                dist[edges[a][i]]=dist[a]+1;
                vis[edges[a][i]]=true;
                q.push(edges[a][i]);
            }
        }
    }
    return -1;
}
// toposort insert node at end of function into the vector, then reverse vector for ascending order


articulation points using dfs(undirected)

int dfsRoot;
vector<int> edges[];
int rootChildren;// set it to 0 at start of each root, used only to find if root is an arti point or not
int dfsCounter = 1;//set it to 1 at start
int dfsNum[];
int dfsLow[];
int dfsParent[];
bool artiVertices[]; 
void DFS(int u)
{
    dfsNum[u] = dfsLow[u] = dfsCounter++;
    for (int i = 0; i < edges[u].size(); ++i)
    {
        int v = edges[u][i];
        if (dfsNum[v] == 0)
        {
            dfsParent[v] = u;
            if (u == dfsRoot)
                ++rootChildren;
            DFS(v);

            // If u is not the root and its child v has no back edge
            // to reach u (meaning there is no cycle), then u is an
            // articulation vertex since it is able to isolate v.
            // if u is root, then root children should be greater than 1 for it to be artivertex
            if (u != dfsRoot && dfsLow[v] >= dfsNum[u])
                artiVertices[u] = true;
            //if(dfsLow[v] > dfsNum[u]) then uv is a bridge
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        }
        // Edge to the parent is not a back edge.
        else if (v != dfsParent[u]) 
            dfsLow[u] = min(dfsLow[u], dfsNum[v]); 
    }
}
memset(dfsNum,0,sizeof(dfsNum));
memset(dfsLow,0,sizeof(dfsLow));
memset(dfsParent,0,sizeof(dfsParent));
memset(artiVertices,false,sizeof(artiVertices));


//printing and finding SCC only run this algo from roots
int dfsCounter = 0;//set it to 1 at start
int dfsNum[];
int dfsLow[];
vector<int> S;
vector<vector<int>> SCC;
void tarjanSCC(int u) {
	dfsLow[u] = dfsNum[u] = dfsCounter++; // dfsLow[u] <= dfsNum[u]
	S.push_back(u); // stores u in a vector based on order of visitation
	vis[u] = 1;
	for (int j = 0; j < (int)edges[u].size(); j++) 
	{
		int v = edges[u][j];
		if (dfsNum[v] == 0)
			tarjanSCC(v);
		if (vis[v]) // condition for update
			dfsLow[u] = min(dfsLow[u], dfsLow[v]); 
	}
	if (dfsLow[u] == dfsNum[u]) 
	{ // if this is a root (start) of an SCC
		printf("SCC %d:", ++numSCC); // this part is done after recursion
		vector<int> temp;
		while (1) {
			int v = S.back(); S.pop_back(); vis[v] = 0;
			temp.push_back(v);
			if (u == v) break; }
		SSC.push_back(temp);
	}
}

//finding scc with no incoming edges , edge starts from 0
//run these algo after tarjan and save numscc with edges in mp-vector<vector<int>> 
//for(int i=0;i<n;i++)cout<<mp[i]<<" ";
    vector<vector<int>> newedge;
    newedge.resize(numscc);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<edges[i].size();j++)
        {
            if(mp[i]!=mp[edges[i][j]])
                newedge[mp[i]].push_back(mp[edges[i][j]]);

        }
    }
    vector<int> indegree;
    indegree.resize(numscc,0);
    for(int i=0;i<numscc;i++)
    {
        for(int j=0;j<newedge[i].size();j++)
        {
                indegree[newedge[i][j]]=1;
        }
    }
    int res=0;
    for(int i=0;i<numscc;i++)if(indegree[i]==0)res++;
    cout<<res<<endl;


//union find by ranks starts from 0
class unionFind {                                              
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  unionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }
  bool issame(int i, int j) { return find(i) == find(j); }
  void unionds(int i, int j) { 
    if (!issame(i, j)) { numSets--; 
    int x = find(i), y = find(j);
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[find(i)]; }
};


// prims and kruskal fail for directed graph (use chu liu algo)
//kruskal algo
int kruskal()**use with edgelist(weight,i,j) only**
{
	sort(edgelist.begin(),edgelist.end());
	int mincost=0;
	//V=number of vertices E=number of edges(size of edgelist)
    unionFind f(V);
	for(int i=0;i<E;i++)
	{
		pair<int,pi> front=edgelist[i];
		if(!f.issame(front.second.first,front.second.second))
		{
			mincost+=front.first;
			f.unionds(front.second.first,front.second.second);
		}
	}
	return mincost;
}

//djikstra - not for negative weight cycle undirected and directed
int n, m;
vpi edges[MAX_N];//adjacency list i,j,weight (vertices 0-n)
vi dist;

void dijkstra(int s) {
    ll LINF = 1e15;
    dist.assign(n, LINF);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dist[s] = 0; pq.push({0, s});
    while (pq.size()) {
        pi a = pq.top(); pq.pop();
        if (a.first > dist[a.second]) continue;
        for (auto v : edges[a.second]) {
            if (dist[v.first] > dist[a.second] + v.second) {
                dist[v.first] = dist[a.second] + v.second;
                par[v.first]=a.second;
                pq.push({dist[v.first], v.first});
            }
        }
    } 
}

// bellman ford- for negative weight cycle also directed and undirected

int n, m, par[MAX_N];
vector<pi> edges[MAX_N];// src,dst,weight
vector<ll> dist;
vector<ll> par;//parent array to print the path

void bellman_ford(int s) {
    ll LINF = 1e15;
    dist.assign(n , LINF);
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto p : edges[u]) {
                if (dist[u] + p.second < dist[p.first]) {
                    par[p.first] = u;//par is for printing path 
                    dist[p.first] = dist[u] + p.second;
                }
            }
        }
    }
}













