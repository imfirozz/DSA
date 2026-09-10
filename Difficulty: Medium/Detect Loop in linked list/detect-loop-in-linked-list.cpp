/*
class Node {
	public:
	int data;
	Node *next;
	
	Node(int x) {
		data = x;
		next = NULL;
	}
} */

class Solution {
	public:
	bool detectLoop(Node* head) {
// 		// code here
// 		if (!head || head->next)
// 			return 0;
		Node*slow = head;
		Node*fast = head;
		
		while (fast && fast->next)
			{
		
			slow = slow->next;
			fast = fast->next->next;
			
			if (slow == fast)
				return 1;
			
		}
		
		return 0;
	}
};
