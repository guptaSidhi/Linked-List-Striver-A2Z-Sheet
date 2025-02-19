// Approach - 1

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map <ListNode*,bool> mp;
        ListNode* temp = head;
        while(temp != NULL)
        {
            if(mp[temp] == true) return temp;
            mp[temp] = true;
            temp = temp -> next;
        }
        return NULL;
    }
};

// Approach - 2

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)
            {
                slow = head;
                while(slow != fast) 
                {
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return NULL;
    }
};