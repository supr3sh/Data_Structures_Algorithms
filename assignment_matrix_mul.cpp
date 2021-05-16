#include<bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int dim[], int n) 
{
    int dp[n][n];
    
    //Cost of multiplying single matrix is zero
    for (int i = 1; i < n; i++) 
        dp[i][i] = 0; 
  	
  	//Len is the number of matrices taken for multiplication
    for (int Len = 2; Len < n; Len++)  
    { 
        for (int i = 1; i < n - Len + 1; i++)  
        {
            int j = i + Len - 1; 
            dp[i][j] = INT_MAX; 
            for (int k = i; k <= j - 1; k++)  
            { 
                int cost = dp[i][k] + dp[k + 1][j] + dim[i - 1] * dim[k] * dim[j]; 
                if (cost < dp[i][j]) 
                    dp[i][j] = cost; 
            } 
        } 
    } 
  
    return dp[1][n - 1]; 
} 

int main()
{
	int arr[] = {1, 2, 3, 4, 3};
	cout<<MatrixChainOrder(arr, 5);
}
