/* Structure of Linked List Node
class Node {
	public:
	int data;
	Node* next;
	
	Node(int x) {
		data = x;
		next = nullptr;
	}
}; */

class Solution {
	public:
	Node* intersectPoint(Node* head1, Node* head2) {
		//  code here
		Node*curr = head1;
		
		while (curr->next)
			{
			curr = curr->next;
			
		}
		
		curr->next = head2;
		
		//   we created circle
		
		Node*slow = head1, *fast = head1;
		
		while (fast && fast->next)
			{
			slow = slow->next;
			fast = fast->next->next;
			
			if (slow == fast)
				{
				break;
			}
			
		}
		slow = head1;
		
		while(slow!=fast)
		{
		    slow = slow->next;
		    fast= fast->next;
		}
		
		return slow;
		
		
	}
};
