//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        int i=0,j=0;
       pair<int,int> p;
        int traverse=1;//1-right,2-left,3-up,4-down
        while(i<matrix.size() && j<matrix[0].size() && i>=0 && j>=0)
        {
            if(matrix[i][j]==1)
            {
                matrix[i][j]=0;
                if(traverse==1) traverse=4;
                else if(traverse==2) traverse=3;
                else if(traverse==3) traverse=1;
                else traverse =2;
            
            }
            switch(traverse)
            { case 1:
                j++;
                break;
                case 2: j--;
                break;
                case 3: i--;
                break;
                case 4: i++;
                break;
                
            }
        }
        if(i==matrix.size())
        {
            p=make_pair(i-1,j);
        }
        else if(i<0){
            p=make_pair(i+1,j);
        }
        else if(j<0){
            p=make_pair(i,j+1);
        }
        else if(j==matrix[0].size()){
            p=make_pair(i,j-1);
        }
        return p;
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends