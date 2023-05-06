//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        string ans = "";
        ans += str[0];
        int i = 1;
        for(int i = 1; i < str.length(); i++) {
            if(str[i] > str[i-1]) break;
            if(str[i] == str[i-1] && str[i] == str[0]) break;
            ans += str[i];
        }
        return ans + rev(ans);
    }
    
    string rev(string s) {
        for(int i = 0, j = s.length()-1; i < j; i++, j--) swap(s[i], s[j]);
        return s;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends