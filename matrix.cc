//reverse by 90
void reverseColumns(int arr[R][C]) 
{ 
    for (int i = 0; i < C; i++) 
        for (int j = 0, k = C - 1;j < k; j++, k--) 
            swap(arr[j][i], arr[k][i]); 
} 
void transpose(int arr[R][C]) 
{ 
    for (int i = 0; i < R; i++) 
        for (int j = i; j < C; j++) 
            swap(arr[i][j], arr[j][i]); 
}  
void rotate90(int arr[R][C]) 
{ 
    transpose(arr); 
    reverseColumns(arr); 
}

//multipy two matrice
void multiply(int mat1[][N],int mat2[][N],int res[][N]) 
{ 
    int i, j, k; 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < N; k++) 
                res[i][j] += mat1[i][k]*mat2[k][j]; 
        } 
    } 
} 

//median in row wise sorted matrix
int binaryMedian(int m[][MAX], int r ,int c) 
{ 
    int min = INT_MAX, max = INT_MIN; 
    for (int i=0; i<r; i++) 
    { 
        if (m[i][0] < min) 
            min = m[i][0]; 
        if (m[i][c-1] > max) 
            max = m[i][c-1]; 
    } 
    int desired = (r * c + 1) / 2; 
    while (min < max) 
    { 
        int mid = min + (max - min) / 2; 
        int place = 0; 
        for (int i = 0; i < r; ++i) 
            place += upper_bound(m[i], m[i]+c, mid) - m[i]; 
        if (place < desired) 
            min = mid + 1; 
        else
            max = mid; 
    } 
    return min; 
} 

//matrix in spiral form
void spiralPrint(int m, int n, int a[R][C]) 
{ 
    int i, k = 0, l = 0; 
    while (k < m && l < n) { 
        for (i = l; i < n; ++i) { 
            cout << a[k][i] << " "; 
        } 
        k++; 
        for (i = k; i < m; ++i) { 
            cout << a[i][n - 1] << " "; 
        } 
        n--; 
        if (k < m) { 
            for (i = n - 1; i >= l; --i) { 
                cout << a[m - 1][i] << " "; 
            } 
            m--; 
        } 
        if (l < n) { 
            for (i = m - 1; i >= k; --i) { 
                cout << a[i][l] << " "; 
            } 
            l++; 
        } 
    } 
}

//maximum path sum(sum of all elements when only allowed to go down or diagonally left right)
int findMaxPath(int mat[][M]) 
{ 
  
    for (int i = 1; i < N; i++) { 
        for (int j = 0; j < M; j++) { 
            if (j > 0 && j < M - 1) 
                mat[i][j] += max(mat[i - 1][j],max(mat[i - 1][j - 1],mat[i - 1][j + 1])); 
            else if (j > 0) 
                mat[i][j] += max(mat[i - 1][j],mat[i - 1][j - 1]); 
            else if (j < M - 1) 
                mat[i][j] += max(mat[i - 1][j],mat[i - 1][j + 1]); 
        } 
    } 
    int res = 0; 
    for (int j = 0; j < M; j++)  
        res = max(mat[N-1][j], res); 
    return res; 
} 



