//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
  private:
    bool isPalindrome(string& str, int st, int en) {
        while(st < en) {
            if(str[st] != str[en]) return false;
            st++;
            en--;
        }
        return true;
    }
    
  public:
    // Function to check if a palindrome pair exists
    bool palindromepair(int N, string arr[]) {
        if(N == 1) return false;
        
        unordered_map<string, int> mp;
        for(int i=0; i<N; i++)
            mp[arr[i]]++;
            
        for(int i=0; i<N; i++) {
            int n = arr[i].length();
            string rev = string(arr[i].rbegin(), arr[i].rend());
            
            if(isPalindrome(arr[i], 0, n-1)) {
                if(mp[arr[i]] > 1) return true;
            }
            else if(mp[rev] > 0) return true;
             
            for(int j=0; j<n-1; j++) {
                if(isPalindrome(arr[i], 0, j) and mp[rev.substr(0, n-1-j)] > 0) return true;
            }
            
            for(int j=0; j<n-1; j++) {
                if(isPalindrome(rev, 0, j) and mp[rev.substr(j+1)] > 0) return true;
            }
        }
        
        return false;
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
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends