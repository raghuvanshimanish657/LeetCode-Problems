//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    
    
    void solve(stack<int>&st,int k){
        
        if(k==0) return; 
        int val=st.top();
       st.pop();
        k--;
        solve(st,k);
        k++;
        if(k!=1)  st.push(val); //if k==1 then it is middle element
        
    }
    
    void deleteMid(stack<int>&s, int n)
    {
         int k;  
         k=ceil((double)(n+1)/2.0); //middle element to be removed from top
         
        solve(s,k);
        
          
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends