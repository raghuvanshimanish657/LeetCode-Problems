//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    
    bool isBoundary(int i, int j, int n, int m)
    {
        if(i==0 || j==0 || i==n-1 || j==m-1)
            return true;
        
        return false;
    }
    
    bool isValid(int i, int j, int n, int m)
    {
        if(i>=0 && i<n && j>=0 && j<m)
            return true;
        
        return false;
    }
    
    bool DFS(int row, int col, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &visited)
    {
        
        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};
        
        bool check = true;
        
        if(isBoundary(row, col, n, m))
            check = false;
            
        for(int i = 0; i<4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(isValid(nrow, ncol, n, m) && !visited[nrow][ncol] && matrix[nrow][ncol]==1)
            {
                visited[nrow][ncol]=1;
                check &= DFS(nrow, ncol, n, m, matrix, visited);
            }
        }
        return check;
    }
    
    
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        vector<vector<int>> visited(N, vector<int>(M, 0));
        int ans = 0;
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<M; j++)
            {
                if(matrix[i][j]==1 && !visited[i][j])
                {
                    visited[i][j]=1;
                    if(DFS(i, j, N, M, matrix, visited))
                        ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends