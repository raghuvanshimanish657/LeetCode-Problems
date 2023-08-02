//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct myComp {
     bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const 
    {
        return a.second > b.second;
    }
};

class Solution {
  public:
    
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        //Using Dijkstra Algorithm
        std::vector<std::vector<int>> und_graph;
        
// Matrix to Undirected Graph
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                und_graph.push_back(std::vector<int>());
                if(A[i][j] == 1){
                    if(j-1 >= 0 && A[i][j-1])und_graph[i*M + j].push_back(i*M + j-1);
                    if(j+1 < M && A[i][j+1])und_graph[i*M + j].push_back(i*M + j+1);
                    if(i-1 >= 0 && A[i-1][j])und_graph[i*M + j].push_back((i-1)*M + j);
                    if(i+1 < N && A[i+1][j])und_graph[i*M + j].push_back((i+1)*M + j);
                }
            }
        }
        
        std::vector<int> min_costs(N*M, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, myComp> cur_costs;
        
        int S = 0;
        min_costs[S] = 0;
        
        for(int i = 0; i<und_graph[S].size(); i++){
            min_costs[und_graph[S][i]] = 1;
            cur_costs.push(make_pair(und_graph[S][i], 1));
        }
        
// Dijkstra Algo finding min cost path
        std::pair<int,int> cur_min;
        int cur_s = 0;
        while(!cur_costs.empty()){
            cur_min = cur_costs.top();
            cur_costs.pop();
            
            if(cur_min.second > min_costs[cur_min.first])continue;
            
            cur_s = cur_min.first;
            for(int i = 0; i<und_graph[cur_s].size(); i++){
                if(1 + min_costs[cur_s] < min_costs[und_graph[cur_s][i]]){
                    min_costs[und_graph[cur_s][i]] = 1 + min_costs[cur_s];
                    cur_costs.push(make_pair(und_graph[cur_s][i], min_costs[und_graph[cur_s][i]]));
                }
            }
        }
        
        
        return (min_costs[X*M + Y] != INT_MAX) ? min_costs[X*M + Y] : -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends