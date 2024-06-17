class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL)
        {
            Node* fut = curr -> next;
            curr -> next = prev;
            curr -> prev = fut;
            prev = curr;
            curr = fut;
        }
        return prev;
    }
};