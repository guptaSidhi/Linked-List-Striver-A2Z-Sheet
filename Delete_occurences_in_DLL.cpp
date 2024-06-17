class Solution
{
public:
    void deleteAllOccurOfX(struct Node **head_ref, int x)
    {
        if (*head_ref == NULL)
            return;

        struct Node dummy;
        dummy.next = *head_ref;
        dummy.prev = NULL;

        struct Node *current = &dummy;

        while (current->next != NULL)
        {
            if (current->next->data == x)
            {
                struct Node *to_delete = current->next;
                current->next = to_delete->next;
                if (to_delete->next != NULL)
                {
                    to_delete->next->prev = current;
                }
            }
            else
            {
                current = current->next;
            }
        }

        *head_ref = dummy.next;
    }
};