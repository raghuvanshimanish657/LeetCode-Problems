//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool getBit(int mask, int i) {
        return mask & (1 << i);
    }
  
    int minVal(int a, int b) {
        // code here
        int count = 0;
        while(b > 0) {
            count += b & 1;
            b >>= 1;
        }
        
        /*
            X ^ A = min
            Min poss value is 0
            
            A=10111011
            count = 1, then we will erase most significant bit
              00111011
            count = 2
              00011011
            count = 3
              00001011
            count = 4
              00000011
            count = 5
              00000001
             count = 6
              00000000   x= 10111011
             count = 7
              A= 10111011
              X= 10111111
            xor= 00000100
            
            Logic: first fill from the most significant bits
                   if all bits are complete
                   then start filling the unset least significant bits
        */
        int res = 0;
        for(int i = 30; i >= 0 && count; i--) {
            if(getBit(a, i)) {
                res |= (1 << i);
                count--;
            }
        }
        
        for(int i = 0; i <= 30 && count; i++) {
            if(getBit(a, i) == false) {
                res |= (1 << i);
                count--;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends