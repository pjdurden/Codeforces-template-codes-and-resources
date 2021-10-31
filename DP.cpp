//kmp search and preprocess
// array would be like 0,1,2(if(pat[1]==pat[2])) or 0,
void kmppre(string pat)
{
    b[0]=0;
    int i=1,j=0;
    q=pat.length();
    while(i<q)
    {
        if(pat[i]==pat[j])
        {
            j++;
            b[i]=j;
            i++;
        }
        else
        {
            if(j!=0)
                j=b[j-1];
            else
            {
                b[i]=0;
                i++;
            }
        }
    }
}

int kmpsearch(string txt,string pat)
{
    int M=pat.length();
    int N=txt.length();
    int i=0;
    int j=0;
    while(i<N)
    {
        if(txt[i]==pat[j])
        {
            i++;j++;
        }
        /**
        if(j==M)
        {
            cout<<"pattern found at i-j";
            j=b[j-1];
        }
        **/
        
        else if(txt[i]!=pat[j])
        {
            if(j!=0)
                j=b[j-1];
            else 
                i++;
        }
    }
    return 0;
}

TSP(recursive)
int dp[15][ (1<<11) -1 ];
int posx[15];
int posy[15];
int n,m,sz;

int solution(int pos,int mask)
{
    if(mask == ((1<<sz)-1) )
        return abs(posx[pos]-posx[0])+abs(posy[pos]-posy[0]);
    if(dp[pos][mask]!=-1)return dp[pos][mask];
    int temp=INT_MAX;
    for(int i=0;i<sz;i++)
    {
        if(!chmask(i,mask))
        {
            int dist=abs(posx[pos]-posx[i])+abs(posy[pos]-posy[i]);
            temp=min(temp,dist+solution(i,mask|(1<<i)));
        }
    }

    return dp[pos][mask]=temp;
}

//digit dp
#include <bits/stdc++.h>
using namespace std;

vector<int> num;
int a, b, d, k;
int DP[12][12][2];
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

int call(int pos, int cnt, int f){
    if(cnt > k) return 0;

    if(pos == num.size()){
        if(cnt == k) return 1;
        return 0;
    }

    if(DP[pos][cnt][f] != -1) return DP[pos][cnt][f];
    int res = 0;

    int LMT;

    if(f == 0){
        /// Digits we placed so far matches with the prefix of b
        /// So if we place any digit > num[pos] in the current position, then the number will become greater than b
        LMT = num[pos];
    } else {
        /// The number has already become smaller than b. We can place any digit now.
        LMT = 9;
    }

    /// Try to place all the valid digits such that the number doesn't exceed b
    for(int dgt = 0; dgt<=LMT; dgt++){
        int nf = f;
        int ncnt = cnt;
        if(f == 0 && dgt < LMT) nf = 1; /// The number is getting smaller at this position
        if(dgt == d) ncnt++;
        if(ncnt <= k) res += call(pos+1, ncnt, nf);
    }

    return DP[pos][cnt][f] = res;
}

int solve(int b){
    num.clear();
    while(b>0){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity

    memset(DP, -1, sizeof(DP));
    int res = call(0, 0, 0);
    return res;
}

int main () {

    cin >> a >> b >> d >> k;
    int res = solve(b) - solve(a-1);
    cout << res << endl;

    return 0;
}