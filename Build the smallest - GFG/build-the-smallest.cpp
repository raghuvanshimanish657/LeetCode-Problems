//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    deque <char> dq;
    int n = num.size();
    int removed = 0;
    for(int i = 0; i < n; i++){
        while(removed < k && dq.size() && dq.back() > num[i]){
            dq.pop_back();
            removed++;
        }
        dq.push_back(num[i]);
    }
    while(removed < k || dq.size() > 1 && dq.front() == '0'){
       if(removed < k){    
         dq.pop_back();
         removed++;
       } else{
           dq.pop_front();
       }
    }
    return string(dq.begin(), dq.end());
}