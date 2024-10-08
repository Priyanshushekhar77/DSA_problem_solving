// method1) HASHING describe in prev qns

// method 2) tortoise and hare algo -> when slow==fast than  makes slow equals to head becz from a starting pt of loop both fast and slow pointer is at equal distance of l; so that again metting point of slow=fast gives the starting point of loop

// https://leetcode.com/problems/linked-list-cycle-ii/description/

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        // detects a cycle
        if (slow == fast)
        {
            // find starting pt of loop
            slow = head;
            // agin collision pt gives the intersection of loop
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
//proof->1.how are u so sure that they will be collide => refer copy
//2.how are u so sure that collide pt giuve sthe starting point of loop =>refer copy
