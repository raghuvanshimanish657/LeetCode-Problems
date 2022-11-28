//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    private:
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> g;
    int size= 0;
    
    public:
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(size==0){
            s.push(x);
        }
        else{
            if(s.size()> g.size()){
                
                if(s.top()> x){
                    g.push(s.top());
                    s.pop();
                    s.push(x);
                }        
                else{
                    g.push(x);
                }
            }
            else{
                
                if(x<= s.top()){
                    s.push(x);
                }             
                else{
                    g.push(x);
                    int t= g.top();
                    g.pop();
                    s.push(t);
                }
            }
        }
        
        size++;
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(size%2==0){
            return ((s.top()+g.top())/2.0);
        }
        else{
            return s.top();
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends