//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            int N = Integer.parseInt(in.readLine());
            String S = in.readLine();
            
            Solution ob = new Solution();
            System.out.println(ob.countWays(N, S));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static int mod=1003;
    static int solve(String s,int i,int j,int isTrue,HashMap<String,Integer> dp)
    {
        if(i>j)
        {
            return 0;
        }
        if(i==j)
        {
            if(isTrue==1)
            {
                return s.charAt(i)=='T'?1:0;
            }
            else
            {
                return s.charAt(i)=='F'?1:0;
            }
        }
        String temp=i+" "+j+" "+isTrue;
        if(dp.containsKey(temp))
        {
            return dp.get(temp);
        }
        int ans=0;
        for(int k=i+1;k<j;k+=2)
        {
            int lt=solve(s,i,k-1,1,dp)%mod;
            int lf=solve(s,i,k-1,0,dp)%mod;
            int rt=solve(s,k+1,j,1,dp)%mod;
            int rf=solve(s,k+1,j,0,dp)%mod;
            if(s.charAt(k)=='&')
            {
                if(isTrue==1)
                {
                    ans=(ans+(rt*lt)%mod)%mod;
                }
                else 
                {
                    ans=(ans+(lt*rf)%mod+(lf*rt)%mod+(lf*rf)%mod)%mod;
                }
            }
            else if(s.charAt(k)=='|')
            {
                if(isTrue==1)
                {
                    ans=(ans+(rt*lt)%mod+(rt*lf)%mod+(rf*lt)%mod)%mod;
                }
                else
                {
                    ans=(ans+(rf*lf)%mod)%mod;
                }
            }
            else if(s.charAt(k)=='^')
            {
                if(isTrue==1)
                {
                    ans=(ans+(lt*rf)%mod+(lf*rt)%mod)%mod;
                }
                else
                {
                    ans=(ans+(lt*rt)%mod+(rf*lf)%mod)%mod;
                }
            }
        }
        dp.put(temp,ans);
        return ans;
    }
    static int countWays(int n, String s){
        // code here
        HashMap<String,Integer> dp=new HashMap<>();
        return solve(s,0,n-1,1,dp);
    }
}