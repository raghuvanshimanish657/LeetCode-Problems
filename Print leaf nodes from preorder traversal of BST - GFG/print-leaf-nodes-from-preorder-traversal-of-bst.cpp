//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leaves;
    void rec(int l, int r, int arr[])
    {
        if(l>r) return;
        if(l==r)
        {
            leaves.push_back(arr[l]);
            return;
        }
        int i;
        for(i=l+1;i<=r;i++)
        {
            if(arr[i]>arr[l]) break;
        }
        rec(l+1,i-1,arr);
        rec(i,r,arr);
    }
    
    vector<int> leafNodes(int arr[],int N) {
        // code here
        int l=0,r=N-1;
        rec(l,r,arr);
        return leaves;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends