//{ Driver Code Starts
import java.io.*;
import java.util.*;


class Node
{
    int data;
    Node left;
    Node right;
    
    Node(int data)
    {
        this.data = data;
        left = null;
        right = null;
    }
    
    public static Node buildTree(String str)
    {
        // Corner Case
        if(str.length()==0 || str.charAt(0)=='N')
            return null;
        
        // Creating array of Strings from input 
        // String after spliting by space
        String ip[] = str.split(" ");
        
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        
        // Push the root to the queue
        Queue<Node> queue = new LinkedList<>(); 
        queue.add(root);
        
        // Starting from the second element
        int i = 1;
        while(queue.size()>0 && i < ip.length)
        {
            
            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();
                
            // Get the current node's value from the string
            String currVal = ip[i];
                
            // If the left child is not null
            if(!currVal.equals("N"))
            {
                    
                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }
                
            // For the right child
            i++;
            if(i >= ip.length)
                break;
                
            currVal = ip[i];
                
            // If the right child is not null
            if(!currVal.equals("N"))
            {
                    
                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));
                    
                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }
        
        return root;
    }
    
    public static Node inputTree(BufferedReader br) throws IOException
    {
        return buildTree(br.readLine().trim());
    }
    
    public static void inorder(Node root)
    {
        if (root == null)
           return;
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            Node node1 = Node.inputTree(br);
            
            
            Node node2 = Node.inputTree(br);
            
            Solution obj = new Solution();
            boolean res = obj.areAnagrams(node1, node2);
            
            int _result_val = (res) ? 1 : 0;
            System.out.println(_result_val);
        }
    }
}

// } Driver Code Ends


/*

Definition for Binary Tree Node
class Node
{
    int data;
    Node left;
    Node right;
    
    Node(int data)
    {
        this.data = data;
        left = null;
        right = null;
    }
}
*/

class Solution {
    public static boolean areAnagrams(Node node1, Node node2) {
        // code here
        Queue<Node> q1 = new LinkedList<>(), q2 = new LinkedList<>();
        q1.offer(node1); q2.offer(node2);
        Map<Integer, Integer> map; int count, size1, size2;
        while(true){
            size1 = q1.size(); size2 = q2.size();
            
            if(size1 != size2) return false;
            if(size1 == 0) return true;
            
            map = new HashMap<>();
            count = 0;
            
            for(int i = 0; i < size1; i++){
                Node cur = q1.poll();
                if(!map.containsKey(cur.data)) count++;
                map.put(cur.data, map.getOrDefault(cur.data, 0) + 1);
                
                if(cur.left != null) q1.offer(cur.left);
                if(cur.right != null) q1.offer(cur.right);
                
            }
            
            for(int i = 0; i < size2; i++){
                Node cur = q2.poll();
                if(!map.containsKey(cur.data)) return false;
                if(map.get(cur.data) == 0) return false;
                map.put(cur.data, map.get(cur.data) - 1);
                if(map.get(cur.data) == 0) count--;
                
                if(cur.left != null) q2.offer(cur.left);
                if(cur.right != null) q2.offer(cur.right);
                
            }
            
            if(count != 0) return false;
        }
    }
}
        
