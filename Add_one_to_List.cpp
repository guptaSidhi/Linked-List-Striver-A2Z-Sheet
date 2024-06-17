class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL)
        {
            Node* fut = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = fut;
        }
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        Node* temp = reverse(head);
        Node* newhead = temp;
        Node* prev = NULL;
        int sum = 1;
        int carry = 0;
        
        while(temp != NULL || carry != 0)
        {
            sum += carry;
            if(temp != NULL) sum += temp -> data;
            if(temp != NULL)
            {
                temp -> data = sum%10;
                prev = temp;
                temp = temp -> next;
            }
            else prev -> next = new Node(sum%10);
            carry = sum /10;
            sum = 0;
        }
        
        return reverse(newhead);
    }
};