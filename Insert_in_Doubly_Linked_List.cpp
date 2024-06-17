void addNode(Node *head, int pos, int data)
{
   // Your code here
   int cnt = 0;
   Node* temp = head;
   while(cnt != pos) {
       temp = temp -> next;
       cnt++;
   } 
   
   if(temp -> next != NULL)
   {
       Node* newnode = new Node(data);
       newnode -> next = temp -> next;
       newnode -> prev = temp;
       temp -> next = newnode;
       newnode -> next -> prev = newnode;
   }
   else
   {
       temp -> next = new Node(data);
       temp -> next -> prev = temp;
   }
}