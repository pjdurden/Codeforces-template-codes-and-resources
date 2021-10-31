// Time complexity: O(n + mlogn)
// Problem link: https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e15;

int n, m;
vector<pi> edges[MAX_N];//edgesacency list
vector<ll> dist;

void dijkstra(int s) {
    ll LINF = 1e15;
    dist.assign(n + 1, LINF);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dist[s] = 0; pq.push({0, s});
    while (pq.size()) {
        pi a = pq.top(); pq.pop();
        if (a.first > dist[u]) continue;
        for (auto v : edges[a.second]) {
            if (dist[v.first] > dist[a.second] + v.second) {
                dist[v.first] = dist[a.second] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    } 
}
 
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    int tc; tc = 1;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}