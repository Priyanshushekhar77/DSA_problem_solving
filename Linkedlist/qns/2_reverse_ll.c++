/* Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/

// recursive solution
//  if(head==NULL || head->next==NULL) return head;
//  ListNode* newhead=reverseList(head->next);
//  ListNode* front=head->next;//initially null
//  front->next=head;
//  head->next=NULL;//discoonecting
//  return newhead;

//general solution
ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *prev = NULL;
    ListNode *temp = head;
    while (temp != NULL)
    {
        ListNode *curr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
    }
    return prev;
}