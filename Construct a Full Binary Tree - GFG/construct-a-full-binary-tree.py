#User function Template for python3

class TreeNode:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

class Solution:
    def solve(self, prei, prem, pre, preM, size, dM, dPre):
        if prei>=size or prem>=size:
            return None
        r = TreeNode(pre[prei])
        if prei<size-1:
            left = pre[prei+1]
            leftM = dM[left]
            if leftM>dM[pre[prei]]:
                r.left = self.solve(prei+1, leftM, pre, preM, size, dM, dPre)
                if prem+1<size:
                    right = preM[prem+1]
                    rightI = dPre[right]
                    r.right = self.solve(rightI, prem+1, pre, preM, size, dM, dPre)
           
        return r
        
    def constructBinaryTree(self, pre, preMirror, size):
        # 
        try:
            d = {}
            for i in range(size):
                d[preMirror[i]] = i
            d1 = {}
            for i in range(size):
                d1[pre[i]] = i
            
            return self.solve(0, 0, pre, preMirror, size, d, d1)
        except Exception as e:
            print(e)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    
    def printInorder(node):
        if node == None:
            return
        printInorder(node.left)
        print(node.data, end = " ")
        printInorder(node.right)
        
    test_cases = int(input())
    for _ in range (test_cases):
        N = int(input())
        pre = list(map(int, input().split()))
        preMirror = list(map(int, input().split()))
        res = Solution().constructBinaryTree(pre, preMirror, N)
        if printInorder(res) != None:
            print(printInorder(res)[:len(printInorder(res))-2])
        print()
# } Driver Code Ends