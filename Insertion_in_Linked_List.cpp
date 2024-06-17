//Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       // Your code here
       if(head == NULL) head = new Node(x);
       else
       {
           Node* temp = new Node(x);
           temp -> next = head;
           head = temp;
       }
       return head;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       // Your code here
       if(head == NULL) head = new Node(x);
       else
       {
            Node* temp = head;
            while(temp->next != NULL) temp = temp->next;
            temp -> next = new Node(x);
       }
       return head;
    }