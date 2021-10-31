#include <bits/stdc++.h>
using namespace std;

string xor1(string a,string b)
{
    string result="";
    int n=b.length();
    for(int i = 1; i < n; i++)
    {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }

    return result;
}

string division(string dividend,string divisor)
{
    int x=divisor.length();
    int y=dividend.length();

    string temp=dividend.substr(0,x);

    while(x<y)
    {
        if(temp[0]=='1')
        {
            temp=xor1(divisor,temp) + dividend[x];
        }
        else
        {
            temp=xor1(string(x,'0'),temp) + dividend[x];
        }

        x++;
    }

    if (temp[0] == '1')
        temp = xor1(divisor, temp);
    else
        temp = xor1(std::string(x, '0'), temp);

    return temp;
}

string encodeData(string data,string key)
{
    int n=key.length();

    string dataWord=data+string(n-1,'0');

    string rem=division(dataWord,key);

    string codeWord=data+rem;

    return codeWord;
}

int main() {

    string data;
    cin>>data;

    string key;
    cin>>key;

    string codeWord=encodeData(data,key);

    cout<<"Encoded word is: "<<codeWord<<endl;

    int t;
    cin>>t;

    while(t--)
    {
        string recieverInput;
        cin>>recieverInput;

        string rem=division(recieverInput,key);


        if(rem=="000")
        { cout<<"No error"<<endl; }
        else
        { cout<<"Error in message"<<endl; }
    }

    return 0;
}
