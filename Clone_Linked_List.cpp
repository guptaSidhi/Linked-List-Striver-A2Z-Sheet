// Approach - 1

class Solution
{
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        if(head == NULL) return head;
        if(head -> next == NULL)
        {
            Node * head2 = new Node(head->data);
            return head2;
        }
        
        unordered_map<Node*, Node*> mp;
        Node *curr = head;
        Node *newhead = new Node(head->data);
        Node *newcurr = newhead;
        mp[curr] = newcurr;
    
        while (curr->next != NULL) {
            newcurr->next = new Node(curr->next->data);
            curr = curr->next;
            newcurr = newcurr->next;
            mp[curr] = newcurr;
        }
    
        // Step 2: Assign arbitrary pointers in the copied list
        curr = head;
        newcurr = newhead;
    
        while (curr != NULL) {
            newcurr->arb = mp[curr->arb];
            curr = curr->next;
            newcurr = newcurr->next;
        }
    
        return newhead;
    }

};
 
// Approach - 2

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
    
        Node* curr = head;
        while(curr != NULL)
        {
            Node* temp = new Node(curr->val);
            temp -> next = curr -> next;
            curr -> next = temp;
            curr = temp -> next;
        }

        curr = head;
        while(curr != NULL)
        {
            if(curr -> random != NULL)
                curr -> next -> random = curr -> random -> next;
            curr = curr -> next -> next;
        }

        Node* newnode = head -> next;
        Node* currold = head;
        Node* currnew = newnode;

        while(currold != NULL)
        {
            currold -> next = currnew -> next;
            currold = currold -> next;
            if(currold != NULL)
            {
                currnew -> next = currold -> next;
                currnew = currnew -> next;
            }
        }

        return newnode;
    }
};