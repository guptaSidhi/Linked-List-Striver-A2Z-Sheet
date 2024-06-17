// Approach - 1

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool> mp;
        ListNode* temp = head;
        while(temp != NULL)
        {
            if(mp[temp] == true) return true;
            mp[temp] = true;
            temp = temp -> next;
        }
        return false;
    }
};

// Approach - 2

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) return true;
        }
        return false;
    }
};