#include <iostream> 
#include<math.h>
using namespace std; 
  
int politness(int n) 
{ 
    int count=0;
    //sqrt(2*n) as max length will be when the sum starts from 1 
    // which follows the equation n^2 - n - (2*sum) = 0
    for(int i=2;i<=sqrt(2*n);i++)
    {
        int a;
        if( (2*n)%i!=0 )continue;
        a=2*n;a/=i;
        a-=(i-1);
        if(a%2!=0)continue;
        a/=2;
        if(a>0)
        {
            /*
            cout<<"sum "<<count+1<<" - " ;
            for(int j=a;j<a+i;j++)
            {
                cout<<j;
                if((j)<a+i-1)cout<<"+";
            }
            cout<<endl;
            */
            count++;
        }
    }
    return count; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int n = 90; 
    cout << "Politness of " << n << " = "
         << politness(n) << "\n"; 
  
    n = 15; 
    cout << "Politness of " << n << " = "
         << politness(n) << "\n"; 
    return 0; 
} 