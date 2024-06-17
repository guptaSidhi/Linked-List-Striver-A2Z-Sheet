class Solution
{
public:
    Node *removeDuplicates(struct Node *head)
    {
        // Your code here
        if (head == NULL || head->next == NULL)
        {
            return head; // If list is empty or has only one node, return head
        }

        struct Node *current = head;

        while (current != NULL && current->next != NULL)
        {
            if (current->data == current->next->data)
            {
                Node *duplicate = current->next;
                current->next = duplicate->next; // Skip the duplicate node

                if (current->next != NULL)
                {
                    current->next->prev = current; // Update prev pointer of next node
                }
            }
            else
            {
                current = current->next; // Move to the next node
            }
        }

        return head;
    }
};