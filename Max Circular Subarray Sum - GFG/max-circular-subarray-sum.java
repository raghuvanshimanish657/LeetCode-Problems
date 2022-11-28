//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Main {
    
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
		while(t-->0){
		    int n = Integer.parseInt(br.readLine().trim());// input size of array
		    int arr[] = new int[n];
		    String inputLine2[] = br.readLine().trim().split(" ");
		    for(int i=0; i<n; i++){
		        arr[i] = Integer.parseInt(inputLine2[i]); // input elements of array
		    }
		    
		    Solution obj = new Solution();
		    
		    System.out.println(obj.circularSubarraySum(arr, n));// print the circularSubarraySum
		}
	}
}



// } Driver Code Ends


class Solution{

    // a: input array
    // n: size of array
    //Function to find maximum circular subarray sum.
    static int kedane(int[] arr){
        int sum = arr[0];
        int maxSum = arr[0];
        for(int i = 1; i<arr.length; i++){
            sum = Math.max(arr[i], sum+arr[i]);
            maxSum = Math.max(maxSum, sum);
        }
        
        return maxSum;
    }
    static int circularSubarraySum(int arr[], int n) {
        int maxSubArrSum = kedane(arr);
        int totalSum=0;
        
        if(maxSubArrSum<0) return maxSubArrSum;
        for(int i = 0; i<n; i++){
            totalSum+=arr[i];
            arr[i]*=-1;
        }
        
        int maxCircularSubArrSum = totalSum + kedane(arr);
        
        return Math.max(maxSubArrSum, maxCircularSubArrSum);
    }
    
}

