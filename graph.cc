//graph class
class Graph 
{ 
    int V;
 	list<int> *adj;    
public: 
    Graph(int V); 
	void addedges(int v, int w);
    void BFS(int s);   
};   
Graph::Graph(int V) 
{   this->V = V; 
    adj = new list<int>[V];} 
void Graph::addedges(int v, int w) 
{ adj[v].push_back(w);} 
void Graph::addedges(int v, int w) 
{ 
    adj[v].push_back(w);
} 

//bfs    
void Graph::BFS(int s) 
{ 
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
    list<int> queue; 
    visited[s] = true; 
    queue.push_back(s);  
    list<int>::iterator i; 
    while(!queue.empty()) 
    { 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 

//dfs
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    visited[v] = true; 
    cout << v << " "; 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
void Graph::DFS(int v) 
{ 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
    DFSUtil(v, visited); 
}

//mother vertex
void Graph::DFSUtil(int v, vector<bool> &visited) 
{ 
    visited[v] = true; 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
}
int Graph::findMother() 
{ 
    vector <bool> visited(V, false); 
    int v = 0; 
    for (int i = 0; i < V; i++) 
    { 
        if (visited[i] == false) 
        { 
            DFSUtil(i, visited); 
            v = i; 
        } 
    }
    fill(visited.begin(), visited.end(), false); 
    DFSUtil(v, visited);  
    for (int i=0; i<V; i++) 
        if (visited[i] == false) 
            return -1; 
  
    return v; 
} 

//no. of nodes at a given level
int Graph::BFS(int s, int l) 
{ 
    bool* visited = new bool[V]; 
    int level[V]; 
    for (int i = 0; i < V; i++) { 
        visited[i] = false; 
        level[i] = 0; 
    } 
    list<int> queue;  
    visited[s] = true; 
    queue.push_back(s); 
    level[s] = 0; 
  
    while (!queue.empty()) { 
        s = queue.front(); 
        queue.pop_front(); 
        for (auto i = adj[s].begin(); 
                  i != adj[s].end(); ++i) { 
            if (!visited[*i]) { 
                level[*i] = level[s] + 1; 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
  
    int count = 0; 
    for (int i = 0; i < V; i++)  
        if (level[i] == l) 
            count++;     
    return count;   
} 

//topological sort
void Graph::topologicalSortUtil(int v, bool visited[],stack<int> &Stack) 
{ 
    visited[v] = true; 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
    Stack.push(v); 
} 
void Graph::topologicalSort() 
{ 
    stack<int> Stack; 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
    for (int i = 0; i < V; i++) 
      if (visited[i] == false) 
        topologicalSortUtil(i, visited, Stack); 
  
    // Print contents of stack 
    while (Stack.empty() == false) 
    { 
        cout << Stack.top() << " "; 
        Stack.pop(); 
    } 
} 

//cycle in directed graph
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
    if(visited[v] == false) 
    { 
        visited[v] = true; 
        recStack[v] = true; 
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
    } 
    recStack[v] = false;
    return false; 
} 
bool Graph::isCyclic() 
{ 
    bool *visited = new bool[V]; 
    bool *recStack = new bool[V]; 
    for(int i = 0; i < V; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
    for(int i = 0; i < V; i++) 
        if (isCyclicUtil(i, visited, recStack)) 
            return true; 
  
    return false; 
} 

//prims minimum spanning tree
int minKey(int key[], bool mstSet[]) 
{ 
    int min = INT_MAX, min_index; 
 
    for (int v = 0; v < V; v++) 
        if (mstSet[v] == false && key[v] < min) 
            min = key[v], min_index = v; 
 
    return min_index; 
} 
void printMST(int parent[], int graph[V][V]) 
{ 
    cout<<"edges \tWeight\n"; 
    for (int i = 1; i < V; i++) 
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
} 
void primMST(int graph[V][V]) 
{ 
    int parent[V]; 
    int key[V]; 
    bool mstSet[V]; 
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    key[0] = 0; 
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    { 
        int u = minKey(key, mstSet); 
        mstSet[u] = true; 
        for (int v = 0; v < V; v++) 
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    } 
    printMST(parent, graph); 
} 

int vis[200];
vector<int> edges[200];
int n,nume;//n=number of vertices,nume=number of edges
bool bipartite(int source)
{
    queue<int> q;
    memset(vis,-1,sizeof(vis));//copy this outside if not a connected graph
    bool flag=true;
    vis[source]=0;
    q.push(source);
    while(!q.empty() and flag)
    {
        int node=q.front();
        q.pop();
        int tempcolor=1-vis[node];
        for(int i=0;i<edges[node].size();i++)
        {
            int xnode=edges[node][i];
            if(vis[xnode]!=-1)
            {
                if(vis[xnode]!=tempcolor)
                {
                    flag=false;
                    break;
                }
                continue;
            }
            vis[xnode]=tempcolor;
            q.push(xnode);
        }
    }
    return flag;
}
