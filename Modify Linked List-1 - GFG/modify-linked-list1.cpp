//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    int count(Node * head){
        int c = 0;
        while(head){
            c++;
            head=head->next;
        }
        return c;
    }
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        int n = count(head);
        Node* p = head;
        Node *prev=NULL;
        //reversing the first half
        for(int i=1;i<=n/2;++i){
            Node * temp = p->next;
            p->next=prev;
            prev=p;
            p=temp;
        }
        Node *l=prev,*r=p;
        if(n&1)
            r=r->next;
        // iterating both halves and changing values as per condition
        for(int i=1;i<=n/2;++i){
            int temp = l->data;
            l->data = r->data-temp;
            r->data = temp;
            l=l->next;
            r=r->next;
        }
        // again combining both the halves
        l=prev;
        prev = p;
        p=l;
        for(int i=1;i<=n/2;++i){
            Node * temp = p->next;
            p->next=prev;
            prev=p;
            p=temp;
        }
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends