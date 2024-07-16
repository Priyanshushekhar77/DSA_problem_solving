/*Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
*/

// naive approach-> store the temp->val in stack and compare each value of temp with stack.top();

// reversell
ListNode *reversell(ListNode *head)
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
bool isPalindrome(ListNode *head)
{
    // 1. find middle using tortoise and hare algo
    // 2. reverse the second half of ll from slow->next;
    // 3. than compare the first half and reversell(slow->next) till second reach to null
    if (head == NULL || head->next == NULL)
        return true;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *sechalf = reversell(slow->next); // reverse from middle
    ListNode *fsthalf = head;
    while (sechalf != NULL)
    {
        if (fsthalf->val != sechalf->val)
        {
            reversell(sechalf);//undo the reverse to make unchange
            return false;
        }
        fsthalf = fsthalf->next;
        sechalf = sechalf->next;
    }
    // undo the reverse to make unchanfe
    reversell(sechalf);
    return true;
}