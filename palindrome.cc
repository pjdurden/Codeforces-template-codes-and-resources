// check palindrome \\to reverse string use reverse(str.begin(),str.end())
bool palindrome(string str)
{
	int l = 0; 
    int h = str.length() - 1; 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        {  
            return true; 
        } 
    } 
    return false;
}

//check palindrome number
bool isPalindrome(int n) 
{ 
   int rev = 0; 
    for (int i = n; i > 0; i /= 10) 
        rev = rev*10 + i%10; 
    return (n==rev); 
}

//insertion to form palindrome dp table to be filled in diagonal fashion
int findMinInsertions(char s[], int n)
{
	int dp[n][n],l,j,g;
	memset(dp,0,sizeof(dp));
	for(g=1;g<n;++g)
		for(l=0,j=g;j<n;++l,++j)
		{
			dp[l][j]=(s[l]==s[j])?dp[l+1][j-1]:(min(dp[l+1][j],dp[l][j-1])+1);
		}
		return dp[0][n-1];
}

//count palindromic subsequence
int countPS(string str)
{
	int n=str.length();
	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
		dp[i][i]=1;
	for(int len=2;len<=n;len++)
		for (int i=0; i<n; i++)
        {
            int k = len+i-1;
            if (str[i] == str[k])
                dp[i][k] = dp[i][k-1] +
                            dp[i+1][k] + 1;
            else
                dp[i][k] = dp[i][k-1] +
                            dp[i+1][k] -
                            dp[i+1][k-1];
        }
    return dp[0][n-1];
 }  

// longest palindromic subsequence
 int lps( string s )
{
 	int n=s.length();
 	int dp[n][n],i,len,j;
 	memset(dp,0,sizeof(dp));
 	for(i=0;i<n;i++)
 		dp[i][i]=1;
 	for(len=2;len<=n;len++)
 		for(i=0;i<n;i++)
 		{
 			j=i+len-1;
 			if(s[i]==s[j] && len==2)
 				dp[i][j]=2;
 			else if(s[i]==s[j])
 				dp[i][j]=dp[i+1][j-1]+2;
 			else
 				dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
 		}
    return dp[0][n-1];
 }

 // longest palindromic substring with no space
int longestPalSubstr(string str) 
{ 
    int n = str.size(); 
    bool table[n][n]; 
    memset(table, 0, sizeof(table));  
    int maxLength = 1; 
    for (int i = 0; i < n; ++i) 
        table[i][i] = true;  
    int start = 0; 
    for (int i = 0; i < n - 1; ++i) { 
        if (str[i] == str[i + 1]) { 
            table[i][i + 1] = true; 
            start = i; 
            maxLength = 2; 
        } 
    } 
    for (int k = 3; k <= n; ++k) { 
        for (int i = 0; i < n - k + 1; ++i) { 
            int j = i + k - 1; 
        if (table[i + 1][j - 1] && str[i] == str[j]) { 
                table[i][j] = true; 
  
                if (k > maxLength) { 
                    start = i; 
                    maxLength = k; 
                } 
            } 
        } 
    } 
  
    cout << "Longest palindrome substring is: "; 
    printSubStr(str, start, start + maxLength - 1); 
  
    // return length of LPS 
    return maxLength; 
} 