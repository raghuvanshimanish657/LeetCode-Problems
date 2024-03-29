//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int totalTime(int n, vector<int> &arr, vector<int> &time) {
        // code here
        int cur = 0;
        unordered_map<int, int> umap;
        for(int i = 0; i < n; i++){
            if(umap.find(arr[i]) == umap.end()){
                umap[arr[i]] = cur + time[arr[i]-1];
            }else{
                if(umap[arr[i]] > cur){
                    cur = umap[arr[i]];
                    umap[arr[i]] = cur + time[arr[i]-1];
                }else{
                    umap[arr[i]] = cur + time[arr[i]-1];
                }
            }
            if(i != n-1)
            cur++;
        }
        return cur;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        
        vector<int> time(n);
        Array::input(time,n);
        
        Solution obj;
        int res = obj.totalTime(n, arr, time);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends