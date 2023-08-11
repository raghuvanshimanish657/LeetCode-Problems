//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int s[], int m, int n) {

       long long int Count[m+1][n+1];
       memset(Count,0,sizeof(Count));
      
       
       
       for(int i = 0 ; i<m+1 ; i++) 
           Count[i][0] = 1;			
       
       for(int j = 1 ; j<n+1 ;j++)
           Count[0][j] = 0;
       
       for(int i = 1; i<m+1 ; i++)
          {
              for(int j = 1 ; j<n+1; j++)
              {
                  if(s[i-1] <= j)
                  {
                      long long int included = Count[i][j-s[i-1]];
                      long long int not_included = Count[i-1][j];
                      
                      Count[i][j] = included + not_included;
                  }
                  
                  else if(s[i-1] > j)
                       Count[i][j] = Count[i-1][j];
              }
          } 
       
       return Count[m][n];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends