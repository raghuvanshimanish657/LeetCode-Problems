//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    static bool cmp(vector<int>a,vector<int>b){
        return a[0]<=b[0];
    }
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
       sort(range.begin(),range.end(),cmp);
       vector<int>ans;
       for(int i=0;i<queries.size();i++){
           bool f=0;
           for(int j=0;j<n;j++){
               if(j!=0 and range[j-1][1]>range[j][0]) queries[i]+=range[j-1][1]-range[j][0]+1;
               
               if(range[j][1]-range[j][0]+1<queries[i])queries[i]-=range[j][1]-range[j][0]+1;
               else{
                   int t=range[j][0];
                   ans.push_back(t+queries[i]-1);
                   f=1;
                   break;
               }
           }
           if(f==0) ans.push_back(-1);
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
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends