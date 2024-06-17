void insert(Node* &head,Node* &tail,int value)
    {
        if(head == NULL)
        {
            head = new Node(value);
            tail = head;
        }
        else 
        {
            tail -> next = new Node(value);
            tail = tail -> next;
        }
    }
    
    Node* constructLL(vector<int>& arr) {
        // code here
        Node* head = NULL;
        Node* tail = NULL;
        for(int i=0;i<arr.size();i++)
        {
            insert(head,tail,arr[i]);
        }
        return head;
    }