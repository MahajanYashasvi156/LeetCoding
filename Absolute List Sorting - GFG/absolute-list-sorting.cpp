//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	Node* next;
	int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " ";
		head = head->next;
	}
	cout << endl;
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

class Solution
{
    
    public:
        Node* sortList(Node* head)
        {
           Node* negHead = NULL;
           Node* negTail = NULL;
           Node* posHead = NULL;
           Node* posTail = NULL;
           
           Node* curr = head;
           
           while(curr)
           {
               Node* nextNode = curr->next;
               if(curr->data<0)
               {
                   if(negHead)
                   {
                       curr->next = negHead;
                   }
                   else
                   {
                       curr->next = NULL;
                        negTail = curr;
                   }
                   negHead = curr;
               }
               else
               {
                   if(posHead)
                   {
                       posTail->next = curr;
                   }
                   else
                   {
                       posHead = curr;
                   }
                   posTail = curr;
                   curr->next = NULL;
               }
               
               curr = nextNode;
           }
           
           if(negHead)
           {
               negTail->next = posHead;
               return negHead;
           }
           return posHead;
        }
};


//{ Driver Code Starts.

// Driver code
int main()
{

	int t = 0;
	int n = 0;
	cin >> t;
	while (t--)
	{
		Node* head = NULL;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// push(&head, a);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			push(&head, arr[i]);
		}
		// printList(head);
		
		Solution ob;
		head=ob.sortList(head);

		printList(head);

	}
	return 0;
}

// } Driver Code Ends