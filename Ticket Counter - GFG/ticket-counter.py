class Solution:
    def distributeTicket(self, N : int, k : int) -> int:

        q=[i for i in range(1,N+1)]
        while len(q)>k:
            q=q[k:]
            q=q[::-1]
        return q[-1]


#{ 
 # Driver Code Starts
t = int(input())
for _ in range(t):
    
    N, K = map(int, input().split())
    
    obj = Solution()
    res = obj.distributeTicket(N, K)
    
    print(res)
# } Driver Code Ends