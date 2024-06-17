// Approach - 1

class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {
            ListNode* fut = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = fut;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL) return head;

        int cnt = 1;
        ListNode* temp = head;
        while(temp->next != NULL)
        {
            temp = temp -> next;
            cnt++;
        }

        temp = head;
        while(temp != NULL)
        {
            if(cnt >= k)
            {
                int nodes = 1;
                ListNode* dummy = temp;
                while(nodes != k) 
                {
                    dummy = dummy -> next;
                    nodes++;
                }

                ListNode* nextnode = dummy -> next;
                dummy -> next = NULL;
                ListNode* reversehead = reverse(temp);
                if(temp == head) head = reversehead;
                else
                {
                    ListNode* trav = head;
                    while(trav -> next != temp) trav = trav -> next;
                    trav -> next = reversehead;
                }
                temp -> next = nextnode;
                temp = nextnode;
                cnt -= k;
            }
            else break;
        }

        return head;
    }
};

// Approach - 2

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1 || head -> next == NULL) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* start = curr;
            ListNode* end = curr;

            // Check if there are k nodes to reverse
            for (int i = 1; i < k && end != NULL; ++i) {
                end = end->next;
            }

            if (end == NULL) break; // Less than k nodes left

            ListNode* nextSegment = end->next; // Node after the k-group
            end->next = NULL; // Separate the k-group

            prev->next = reverse(start); // Link reversed k-group
            start->next = nextSegment; // Connect the rest of the list

            prev = start; // Update prev to the end of the reversed segment
            curr = nextSegment; // Move curr to the next segment
        }

        head = dummy->next;
        delete dummy;

        return head;
    }
};