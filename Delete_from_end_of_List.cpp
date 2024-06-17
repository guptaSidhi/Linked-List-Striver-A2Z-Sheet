// Approach - 1

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 1;
        ListNode* temp = head;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
            cnt++;
        }

        int pos = cnt - n;
        if(pos == 0) return head -> next;

        cnt = 1;
        temp = head;
        while(cnt != pos)
        {
            temp = temp -> next;
            cnt++;
        }

        temp -> next = temp -> next -> next;
        return head;
    }
};

//Approach - 2
// Here we are using 2 pointers, suppose you have a line of n persons, and you are asked to remove last 3rd person from it, then we can do in such a way that we make a pointer traverse from the start and reach the next 3rd Person, means we cover the distance, but problem is that, how do we know that person is 3rd Last, for this we make another pointer which starts from end, Now when the first pointer reaches the last person, means second pointer reaches the 4th last Person, because we are some steps ahead in first pointer.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        while(n--) ptr2 = ptr2 -> next;

        if(ptr2 == NULL) return ptr1 -> next;

        while(ptr2 -> next != NULL)
        {
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }

        ptr1 -> next = ptr1 -> next -> next;
        return head;
    }
};