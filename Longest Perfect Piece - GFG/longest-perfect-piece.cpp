//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        int ans = 0;
        deque<int> maxDeq, minDeq;
        for(int i = 0, j = 0; j < N; j++){
            // maxDeq->maintaining non-increasing order deque
            while(maxDeq.size() and arr[j] > maxDeq.back()) 
                maxDeq.pop_back();
            maxDeq.push_back(arr[j]);
            
            // minDeq->maintaining non-decreasing order deque
            while(minDeq.size() and arr[j] < minDeq.back()) 
                minDeq.pop_back();
            minDeq.push_back(arr[j]);
            
            // removing those which doesn't contribute
            while(maxDeq.front()-minDeq.front() > 1){
                if(maxDeq.front() == arr[i]) maxDeq.pop_front();
                if(minDeq.front() == arr[i]) minDeq.pop_front();
                i++;
            }
            
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends