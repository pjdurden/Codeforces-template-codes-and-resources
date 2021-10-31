// Given n different values of coins
// 1) Find the number of distinct ways to sum up to x
// 2) Find the number of distinct "ordered" ways to sum up to x
// 3) Find the minimum number of coins required to sum up to x
// Time complexity: O(nx)

#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;



void solve() {
    int n, x; cin >> n >> x;
    int arr[n]; 
    for (int i = 0; i < n; i++) cin >> arr[i];

    // 1) Problem link: https://cses.fi/problemset/task/1635
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) 
        for (int j : arr) 
            if (i - j >= 0) 
                dp[i] = (dp[i] + dp[i - j]) % MOD; 
    cout << dp[x] << "\n";

    //recursive
    int dp[1000009];
    int val[105];

    int solution(int price)
    {

        if(price==0)return 1;
        if(price<0)return 0;  
        if(dp[price]!=-1)return dp[price];
        ll temp=0;
        for(int i=0;i<n;i++)temp=(temp+solution(price-val[i]))%mod;
        
        return dp[price]=temp;
    }

    // 2) Problem link: https://cses.fi/problemset/task/1636
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int j : arr) 
        for (int i = 1; i <= x; i++) 
            if (i - j >= 0) 
                dp[i] = (dp[i] + dp[i - j]) % MOD; 
    cout << dp[x] << "\n";

    //recursive
    int n,m,q,r;

    int dp[100][1000009];
    int val[105];

    int solution(int price,int ind)
    {
        
        if(price==0)return 1;
        if(ind==n)return 0;
        if(price<0)return 0;  
        if(dp[ind][price]!=-1)return dp[ind][price];
        int temp=0;
        temp=(solution(price-val[ind],ind)%mod + solution(price,ind+1)%mod )%mod;
        return dp[ind][price]=temp;
    }

    // 3) Problem link: https://cses.fi/problemset/task/1634
    vector<int> dp(x + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) 
        for (int j : arr) 
            if (i - j >= 0) 
                dp[i] = min(dp[i], dp[i - j] + 1);
    cout << (dp[x] == INF ? -1 : dp[x]) << "\n";
}

//recursive

int n,m,q,r;

int dp[1000009];
int val[105];

int solution(int price)
{
    if(price==0)return 0;
    if(price<0)return 10000000;  
    if(dp[price]!=-1)return dp[price];
    ll temp=10000000;
    for(int i=0;i<n;i++)
    {
        temp=min(temp,1+(ll)solution(price-val[i]));
    }
    return dp[price]=temp;
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
