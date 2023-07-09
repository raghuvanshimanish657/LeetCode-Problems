//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int missingNumber(int arr[], int n) 
    { 
        int ans = 0;
        int val;
        sort(arr, arr+n);
        int i;
        for(i = 0; i < n; i++){
            if(arr[i] <= 0){
                
            }
            else{
                ans = arr[i];
                break;
            }
        }
        if(ans > 1)
            return 1;
        ans++;
        for(int j = i+1; j < n; j++)
            if(arr[j] == ans)
                ans++;
        return ans;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends