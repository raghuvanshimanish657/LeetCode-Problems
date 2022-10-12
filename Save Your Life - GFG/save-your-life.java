//{ Driver Code Starts
import java.io.*;
import java.util.*;

// } Driver Code Ends
class Solution{
    static String maxSum(String w,char x[],int b[], int n){
        if(w.length() == 1)
            return w;
            
        int curStart = 0, maxStart =Integer.MIN_VALUE;
        int maxEnd = 0;
        int curSum = 0, maxSum = Integer.MIN_VALUE;
        
        HashMap<Character, Integer> mp = new HashMap<>();
        for(int i = 0; i < n; i++){
            mp.put(x[i], b[i]);
        }
        
        for(int i = 0; i < w.length(); i++){
            curSum += mp.getOrDefault(w.charAt(i), (int)w.charAt(i));
            if(curSum > maxSum){
                maxSum = curSum;
                maxStart = curStart;
                maxEnd = i;
            }
            if(curSum <= 0){
                curStart = i+1;
                curSum = 0;
            }
        }
        return w.substring(maxStart, maxEnd+1);
    }
}

//{ Driver Code Starts.
class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String w = read.readLine();
            int n = Integer.parseInt(read.readLine());
            String TE[] = read.readLine().trim().split(" ");
            char x[] = new char[n];
            for(int i = 0;i<n;i++)
            {
                x[i] = TE[i].charAt(0);
            }
            
            String TR[] = read.readLine().trim().split(" ");
            int b[] = new int[n];
            for(int i = 0;i<n;i++)
            {
                b[i] = Integer.parseInt(TR[i]);
            }
           
            Solution ob = new Solution();
            System.out.println(ob.maxSum(w,x,b,n));
        }
    }
}
// } Driver Code Ends