//multipy
string multiply(string num1, string num2) 
{ 
    int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) 
    return "0"; 
    vector<int> result(len1 + len2, 0); 
    int i_n1 = 0;  
    int i_n2 = 0;  
    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
        i_n2 = 0;  
        for (int j=len2-1; j>=0; j--) 
        { 
            int n2 = num2[j] - '0'; 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
            carry = sum/10; 
            result[i_n1 + i_n2] = sum % 10;   
            i_n2++; 
        } 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
        i_n1++; 
    } 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
    if (i == -1) 
    return "0"; 
    string s = ""; 
    while (i >= 0) 
        s += std::to_string(result[i--]); 
    return s; 
} 
//divide
string longDivision(string number, int divisor) 
{ 
    string ans; 
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) 
        temp = temp * 10 + (number[++idx] - '0'); . 
    while (number.size() > idx) { 
        ans += (temp / divisor) + '0'; 
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
    if (ans.length() == 0) 
        return "0"; 
    return ans; 
} 

// TOTAL SUBSTRINGS substring=n*(n+1)/2

//longest common subsequence
int lcs(string X, string Y, int m, int n) 
{ 
    int L[m + 1][n + 1]; 
    int i, j; 
    for (i = 0; i <= m; i++) { 
        for (j = 0; j <= n; j++) { 
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
  
            else if (X[i - 1] == Y[j - 1]) 
                L[i][j] = L[i - 1][j - 1] + 1; 
  
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
        } 
    } 
    return L[m][n]; 
}
//sort string increasing
 sort(s.begin(), s.end()); 
 //descending order
  sort(s.begin(), s.end(), greater<char>()); 

//length of longest balanced subsequence
  int maxLength(char s[], int n) 
{ 
    int dp[n][n]; 
    memset(dp, 0, sizeof(dp)); 
    for (int i = 0; i < n - 1; i++) 
        if (s[i] == '(' && s[i + 1] == ')') 
            dp[i][i + 1] = 2; 
    for (int l = 2; l < n; l++) { 
        for (int i = 0, j = l; j < n; i++, j++) { 
            if (s[i] == '(' && s[j] == ')') 
                dp[i][j] = 2 + dp[i + 1][j - 1]; 
            for (int k = i; k < j; k++) 
                dp[i][j] = max(dp[i][j], 
                               dp[i][k] + dp[k + 1][j]); 
        } 
    } 
  
    return dp[0][n - 1]; 
}


