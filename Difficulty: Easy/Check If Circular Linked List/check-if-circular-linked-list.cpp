/* Link list Node
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
class Solution {
  public:
    bool isCircular(Node *head) {
        // code here
           if(!head)
        return 0;
        Node*temp = head->next;
        
     
        while(temp&& temp!=head)
        {
            temp=temp->next;
        }
        
        if(!temp)
        return 0;
        return 1;
    }
};