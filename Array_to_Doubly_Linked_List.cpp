void solve(Node* &head,Node* &tail,int value)
    {
        if(head == NULL)
        {
            head = new Node(value);
            tail = head;
        }
        else
        {
            Node* temp = new Node(value);
            tail -> next = temp;
            temp -> prev = tail;
            tail = tail -> next;
        }
    }
    
    Node* constructDLL(vector<int>& arr) {
        // code here
        Node* head = NULL;
        Node* tail = NULL;
        for(int i=0;i<arr.size();i++)
        {
            solve(head,tail,arr[i]);
        }
        return head;
    }