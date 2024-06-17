class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        Node* start = head;
        Node* end = head;
        while(end -> next != NULL) end = end -> next;
        
        vector <pair<int,int>> ans;
        
        while(start->data < end->data)
        {
            int sum = start->data + end->data;
            if(sum == target)
            {
                ans.push_back({start->data,end->data});
                start = start -> next;
                end = end -> prev;
            }
            else if(sum > target) end = end -> prev;
            else start = start -> next;
        }
        
        return ans;
    }
};