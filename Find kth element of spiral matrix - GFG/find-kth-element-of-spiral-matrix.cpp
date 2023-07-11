//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends

class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int A[MAX][MAX], int n, int m, int k)
    {
	// Your code here
	int count =0;
	    int a=0,b=0;
	    while(a<n && b<m){
	        for(int i=b;i<m;i++){
	            count++;
	            if(count==k)
	            return A[a][i];
	        }
	        
	        for(int i=a+1;i<n;i++){
	            count++;
	            if(count==k)
	            return A[i][m-1];
	        }
	        if((n-1)!=a){
	            for(int i=m-2;i>=b;i--){
	                count++;
	                if(count==k)
	                return A[n-1][i];
	            }
	        }
	        if((m-1)!=b){
	            for(int i=n-2;i>a;i--){
	                count++;
	                if(count==k)
	                return A[i][b];
	            }
	        }
	        a++;b++;n--;m--;
	    }
	    return 0;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends