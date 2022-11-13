//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        string str;
        int count=0,i=0,j=0;
        while(j<S.size()){
            if(S[j]==W[i]){
                S.erase(j,1);
                i++;
                j--;
                if(i==W.size()){
                    count++;
                    i=0;
                    j=-1;
                }
            }
            j++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends