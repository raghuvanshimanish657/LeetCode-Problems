//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int ans=0;
        int n=matrix.size(),m=matrix[0].size();
        int d[]={1,0,-1,0,1,-1,-1,1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                if(matrix[i][j]==1){
                    
                    for(int k=0;k<8;k++){
                        int nx=i+d[k],ny=j+d[k+1];
                        if(nx>-1 && nx<n && ny>-1 && ny<m && matrix[nx][ny]==0){
                            cnt++;
                        }
                    }
                }
                if(cnt%2==0 && cnt!=0) ans++;
            }
        }
        return ans;
        // Code here
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends