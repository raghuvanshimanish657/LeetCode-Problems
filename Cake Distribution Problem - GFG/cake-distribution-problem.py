#User function Template for python3

class Solution():
    def maxSweetness(self, sweetness, n, k):
        def ok(minv):
            s, cnt = 0, 0
            for e in sweetness:
                s += e
                if s >= minv:
                    cnt += 1
                    s = 0
            return cnt >= k+1
            
        lo, hi = min(sweetness), sum(sweetness)+1

        while lo < hi:
            mi = lo+(hi-lo)//2
            if not ok(mi):
                hi = mi
            else:
                lo = mi+1
        return lo-1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

for _ in range(int(input())):
    n,k = map(int, input().split())
    sweetness = [int(i) for i in input().split()]
    print(Solution().maxSweetness(sweetness, n,k))
# } Driver Code Ends