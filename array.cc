//dividing using multiplicative inverse
int inv(int x)
{
    return binpow(x, mod - 2);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}


long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

//eulerphi(totient)
ll eulerphi(ll x)
{
    ll eulrphi=x;
    for(int i=2;i*i<=x and x!=1;i++)
    {
        if(x%i==0)
        {
            while(x%i==0)
            {
                x/=i;
            }
            eulrphi=(eulrphi*(i-1))/i;
        }
    }
    if(x>1)
    {
        eulrphi=(eulrphi*(x-1))/x;
    }
    return eulrphi;
}

//sieve
void sieve()
{
    memset(dp,true,sizeof dp);
    dp[0]=dp[1]=false;
    for(int i=2;i<1000010;i++)
    {
        if(dp[i])
        {
            for(int j=2*i;j<1000010;j+=i)
                dp[j]=false;
        }
    }
}

//catalan
int binomialcoeff(int n,int k)
{
    long long res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i) {
        res = mul(res,(n - i));
        res =divs(res,i+1);
    }
 
    return res;
}
int catalan(int n)
{
    return divs(binomialcoeff( mul(2,n) , n ),n+1);
    
}

//binomial coeff (if multiple queries)
void binomial(int n, int k)// n and k are the size ranges of dp
{
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
}

ll binomialCoeff(int n, int k)//single query
{
    ll C[k + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}



//pisano
ll pisano(ll m) {
    vector<long> v{1, 1};
    while (true) {
        auto t = (v[v.size() - 1] + v[v.size() - 2]) % m;
        v.push_back(t);
        if (t == 0 && v.size() % 2 == 0 &&
            equal(v.begin(), v.begin() + v.size() / 2,
                       v.begin() + v.size() / 2, v.end())) {
            return v.size() / 2;
        }
    }
    return v.size() / 2;
}

//fibbonaci number (log n) using binary exponentiation
// returns Fn,Fn+1
pair<int, int> fib (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}


// for an array or string of n elements subarrays-n*(n-1)/2 subsequences-2^n - 1 
//min swaps to sort array using graph
int minSwaps(int arr[], int n) 
{ 
    pair<int, int> arrPos[n]; 
    for (int i = 0; i < n; i++) 
    { 
        arrPos[i].first = arr[i]; 
        arrPos[i].second = i; 
    } 
    sort(arrPos, arrPos + n);  
    vector<bool> vis(n, false); 
    int ans = 0; 
    for (int i = 0; i < n; i++) 
    { 
        if (vis[i] || arrPos[i].second == i) 
            continue; 
        int cycle_size = 0; 
        int j = i; 
        while (!vis[j]) 
        { 
            vis[j] = 1; 
            j = arrPos[j].second; 
            cycle_size++; 
        } 
        if (cycle_size > 0) 
        { 
            ans += (cycle_size - 1); 
        } 
    } 
    return ans; 
} 

//pair with sum x
void printPairs(int arr[], int arr_size, int sum) 
{ 
    unordered_set<int> s; 
    for (int i = 0; i < arr_size; i++) { 
        int temp = sum - arr[i]; 
        if (s.find(temp) != s.end()) 
            cout << arr[i] << temp;
        s.insert(arr[i]); 
    } 
}

//binary search
int binarySearch(int arr[], int low, int high, int key) 
{ 
    if (high < low) 
        return -1; 
    int mid = (low + high) / 2;
    if (key == arr[mid]) 
        return mid; 
    if (key > arr[mid]) 
        return binarySearch(arr, (mid + 1), high, key); 
    return binarySearch(arr, low, (mid - 1), key); 
} 

//peak element using binary search
int findPeakUtil(int arr[], int low,int high, int n) 
{ 
    int mid = low + (high - low) / 2; 
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) 
        return mid; 
    else if (mid > 0 && arr[mid - 1] > arr[mid]) 
        return findPeakUtil(arr, low, (mid - 1), n); 
    else
        return findPeakUtil(arr, (mid + 1), high, n); 
} 

//to find array is subset of given array
int binarySearch(int arr[], int low,int high, int x) 
{ 
    if(high >= low) 
    { 
        int mid = (low + high)/2;
        if(( mid == 0 || x > arr[mid-1]) && (arr[mid] == x)) 
            return mid; 
        else if(x > arr[mid]) 
            return binarySearch(arr, (mid + 1), high, x); 
        else
            return binarySearch(arr, low, (mid -1), x); 
    } 
    return -1; 
}  
void exchange(int *a, int *b) 
{ 
    int temp; 
    temp = *a; 
    *a = *b; 
    *b = temp; 
} 
int partition(int A[], int si, int ei) 
{ 
    int x = A[ei]; 
    int i = (si - 1); 
    int j; 
  
    for (j = si; j <= ei - 1; j++) 
    { 
        if(A[j] <= x) 
        { 
            i++; 
            exchange(&A[i], &A[j]); 
        } 
    } 
    exchange (&A[i + 1], &A[ei]); 
    return (i + 1); 
} 
bool isSubset(int arr1[], int arr2[], 
                        int m, int n) 
{ 
    int i = 0; 
  
    quickSort(arr1, 0, m-1); 
    for (i=0; i<n; i++) 
    { 
        if (binarySearch(arr1, 0, m - 1, 
                        arr2[i]) == -1) 
        return 0; 
    } 
    return 1; 
} 

//longest increasing subsequence
int lis( int arr[], int n )  
{  
    int lis[n]; 
    lis[0] = 1;    
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
    } 
    return *max_element(lis, lis+n); 
}  

//size of largest histogram
int largestRectangleArea(vector<int>& heights) {
        
        int curr=0;
        int maxs=0;
        stack<int> st;
        for(int i=0;i<heights.size();i++)
        {
            if(st.empty() || heights[st.top()]<heights[i])
                st.push(i);
            else
            {
                int tp=st.top();
                st.pop();
                curr=heights[tp]* ( st.empty() ? i :i-st.top()-1 ) ;
                maxs=max(curr,maxs);
                i--;
            }
        }
        int i=heights.size();
        while(!st.empty())
        {

            int tp=st.top();
            st.pop();
            curr=heights[tp]* ( st.empty()?i:i-st.top()-1) ;
            maxs=max(curr,maxs);            
        }
    return maxs;
}

vector<pi> primefact(ll n)
{
    vector<pi> temp;
    for(ll i=2;i*i<=n;i++)
    {
        int cnt=0;
        while(n%i==0)
        {
            n/=i;
            cnt++;
        }
        if(count>0)
            temp.pb({cnt,i});
    }
    if(n!=1)
        temp.pb({1,n});
    return temp;
}

