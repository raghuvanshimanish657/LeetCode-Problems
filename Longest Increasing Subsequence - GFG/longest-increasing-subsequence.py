#User function Template for python3

class Solution:
    
    #Function to find length of longest increasing subsequence.
    def longestSubsequence(self,arr,n):
        # code here
        ans = []
        n = len(arr)
        def lower_bound(v, arr, n):
            l = 0
            r = n - 1
            while(l < r):
                mid = l + (r - l)//2
                if arr[mid] >= v:
                    r = mid
                else:
                    l = mid + 1
            return l
        c = 0
        for i in range(n):
            if ans == [] or ans[-1] < arr[i]:
                ans.append(arr[i])
                c += 1
            else:
                l = lower_bound(arr[i], ans, c)
                ans[l] = arr[i]
        return len(ans)



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        a = [ int(x) for x in input().split() ]
        ob=Solution()
        print(ob.longestSubsequence(a,n))
# } Driver Code Ends