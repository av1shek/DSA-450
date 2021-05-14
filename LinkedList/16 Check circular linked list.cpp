bool isCircular(Node *head)
{
    if(head==NULL || head->next==NULL) return false;
    
   Node* fast = head, *slow = head;
   
   while(fast && fast->next)
   {
       fast = fast->next->next;
       slow = slow->next;
       
       if(fast == slow)
       {
           slow = head;
           while(fast!=slow)
           {
               fast = fast->next;
               slow = slow->next;
           }
           return fast==head;
       }
   }
   return false;
}