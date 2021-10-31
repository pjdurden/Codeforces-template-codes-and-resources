#include<bits/stdc++.h>
using namespace std;

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        int arr[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>arr[i][j];
        int ans=0;
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<m/2;j++)
            {
                int left=abs(arr[i][j]-arr[n-i][j]);
                int right=abs(arr[i][j]-arr[i][m-j]);
                ans+=min(left,right);
            }
        }
        cout<<ans<<"\n";

    }
    return 0;
}
