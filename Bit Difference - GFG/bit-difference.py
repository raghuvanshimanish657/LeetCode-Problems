#User function Template for python3

class Solution:
    def countBits(self, N, A):
        out = 0
        for i in range(32):
            count = 0
            for j in range(N):
                if A[j] & (1<<i): count += 1
            out += (count*(N-count)*2)
        return out % (1000000007)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        A = input().split()
        for it in range(N):
            A[it] = int(A[it])
        
        ob = Solution()
        print(ob.countBits(N, A))
# } Driver Code Ends