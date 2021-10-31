#include<bits/stdc++.h>
using namespace std;

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int ends=a+b+c;
        int start=(2*max(a,max(b,c)))-a-b-c;
        int d;
        for(int i=start+1;i<ends;i++)
        {
            if(a+i+c>b and a+i+b>c and b+i+c>a)
            {
                d=i;
                break;
            }
        }
        cout<<d<<"\n";

    }
    return 0;
}
