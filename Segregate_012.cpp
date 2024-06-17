class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        if(head == NULL || head -> next == NULL) return head;
        // Add code here
        Node* zero = new Node(-1);
        Node* one = new Node(-1);
        Node* two = new Node(-1);
        
        Node* temp1 = zero;
        Node* temp2 = one;
        Node* temp3 = two;
        
        Node* temp = head;
        while(temp != NULL)
        {
            if(temp -> data == 0)
            {
                zero -> next = temp;
                zero = zero -> next;
            }
            else if(temp -> data == 1)
            {
                one -> next = temp;
                one = one -> next;
            }
            else
            {
                two -> next = temp;
                two =  two -> next;
            }
            temp = temp -> next;
        }
        
        two -> next = NULL;
        
        if(temp2 -> next == NULL){
            zero -> next = temp3 -> next;
        }
        else
        {
            zero -> next = temp2 -> next;
            one -> next = temp3 -> next;
        }
        return temp1 -> next;
    }
};