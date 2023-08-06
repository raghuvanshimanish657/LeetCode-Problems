//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
   public:
    //Complete this function
    vector<string> str;
    // here k indicates the starting index to start permutations
    void helper(string s,vector<string>&str,int k) { 
        int n = s.size(); // s is the original string
        if(k == s.size()) {
            str.push_back(s);
            return;
        }
        for(int i=k;i<n;i++) {
            swap(s[i],s[k]);
            helper(s,str,k+1); // k+1 indicates to go to next index
            swap(s[i],s[k]); // to get original order of string
            
        }
        
    }
    vector<string> permutation(string S)
    {
        helper(S,str,0);
        sort(str.begin(),str.end()); // to get correct lexigrophic order of string in alphabetical wise
        return str;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends