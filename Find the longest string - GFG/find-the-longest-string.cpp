//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words){
        // sorting such that longest and lexicographically smallest string will be at front
        sort(words.begin(), words.end(), [&](string &a, string &b){
            return a.size() == b.size() ? a < b : a.size() > b.size(); 
        });
        // Now the only task is to check for presence of prefix strings
        
        // It will store the strings which satisfy all the required condition 
        unordered_set<string> um;
        
        um.insert("");
        
        string res = "";
        
        for(int i = words.size() -1; i >= 0 ; i--){
            int n = words[i].size();
            string prefix = words[i].substr(0,n-1); // words[i] = "abcd" than prefix = "abc"       
            if(um.find(prefix) != um.end()){
                res = words[i];
                um.insert(words[i]);
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends