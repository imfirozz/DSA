/* The structure of linked list Node
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = nullptr;
  }
};
*/

class Solution {
public:
    pair<Node *, Node *> splitList(Node *head) {

        Node *slow = head;
        Node *fast = head;

        while(fast->next != head && fast->next->next != head)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast->next->next == head)
            fast = fast->next;

        Node *head2 = slow->next;

        slow->next = head;
        fast->next = head2;

        return {head, head2};
    }
};