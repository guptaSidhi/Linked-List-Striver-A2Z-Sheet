Node* merge(Node* head1,Node* head2)
{
    Node* newnode = new Node(-1);
    Node* temp = newnode;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1 -> data <= head2 -> data)
        {
            temp -> bottom = new Node(head1 -> data);
            temp = temp -> bottom;
            head1 = head1 -> bottom;
        }
        else
        {
            temp -> bottom = new Node(head2 -> data);
            temp = temp -> bottom;
            head2 = head2 -> bottom;
        }
    }
    
    while(head1 != NULL)
    {
        temp -> bottom = new Node(head1 -> data);
        temp = temp -> bottom;
        head1 = head1 -> bottom;
    }
    
    while(head2 != NULL)
    {
        temp -> bottom = new Node(head2 -> data);
        temp = temp -> bottom;
        head2 = head2 -> bottom;
    }
    
    return newnode -> bottom;
}

Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL || root -> next == NULL) return root;
   Node* temp = flatten(root->next);
   return root = merge(root,temp);
}