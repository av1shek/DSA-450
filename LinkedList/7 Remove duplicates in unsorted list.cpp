class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     if(head==NULL || head->next==NULL) return head;
      unordered_set<int> s;
      s.insert(head->data);
      
      Node *curr = head, *next = head->next;
      
      
      while(next != NULL)
      {
          if(s.find(next->data) == s.end())
          {
              curr->next = next;
              curr=next;
              s.insert(curr->data);
          }

        next = next->next;

      }
      curr->next = next;
      return head;
    }
};