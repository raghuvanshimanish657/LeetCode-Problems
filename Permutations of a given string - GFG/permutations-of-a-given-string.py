#User function Template for python3

class Solution:
    def __init__(self):
        self.li = []
    def find_permutation(self, S):
        # Code here
        n = len(S)
        def f(st,i):
            x = "".join(st)
            if i==n:
                self.li.append(x)
                return 
            if x not in self.li:
                self.li.append(x)
            for j in range(n-1):
                st[i],st[j] = st[j],st[i]
                f(st,i+1)
        st = list(S)
        f(st,0)
        self.li = list(set(self.li))
        self.li.sort()
        return self.li
        



#{ 
 # Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__':
	t=int(input())
	for i in range(t):
		S=input()
		ob = Solution()
		ans = ob.find_permutation(S)
		for i in ans:
			print(i,end=" ")
		print()
# } Driver Code Ends