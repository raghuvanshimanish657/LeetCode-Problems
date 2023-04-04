//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int a = 0,b = 0;
    for(int i = 0;i < str.size();i++)
    {
        if(str[i] == 'a')
        {
            while(str[i] == 'a') i++;
            a++;
            i--;
        }else{
            while(str[i] == 'b') i++;
            b++;
            i--;
        }
    }
    return min(a,b) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends