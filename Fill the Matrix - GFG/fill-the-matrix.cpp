//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){ 
        vector<int> dx = {-1, 0, +1, 0};
        vector<int> dy = {0, -1, 0, +1};
        vector<vector<int>> vis(N, vector<int>(M));
        int ans = -1;
        --x; --y;
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = 1;
        while(!q.empty()) {
            int sz = q.size();
            ++ans;
            while(sz--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0; i<4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx>=0 && nx<N && ny>=0 && ny<M && vis[nx][ny]==0) {
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends