//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     bool isStraightHand(int n, int m, vector<int> &arr) {
        // code here
        
        if(n%m) return 0;
        sort(arr.begin(),arr.end());
        multiset<int> st;
        for(int i=0;i<n;i++){
            st.insert(arr[i]);
        }
        while(!st.empty()){
            int p=*st.begin();
            st.erase(st.begin());
            for(int i=1;i<m;i++){
                auto it=st.upper_bound(p);
                if(it!=st.end() && *it!=p+1) return 0;
                if(it==st.end()) return 0;
                st.erase(it);
                p=p+1;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends