/* PROOF=> The relative speed between them causes the gap to decrease by one node in each iteration (fast gains two nodes while slow gains one node). This continuous reduction ensures that the difference between their positions decreases steadily. Mathematically, if the fast pointer gains ground twice as fast as the slow pointer, the difference in their positions reduces by one node after each step. Consequently, this reduction in the distance between them continues until the difference becomes zero.

https://leetcode.com/problems/linked-list-cycle/description/
*/
// METHOD 1//HASHING
unordered_map<Node *> mp; // unordered_set<Node*>st;
temp = head;
while (temp1 != NULL)
{
    if (mp.find(temp) != mp.end)
        return true; // return temp;
    mp[temp] = 1     // mp.insert(temp)
        temp = temp->next;
}
return false; // NULL
// comment line is for starting pt of loop of ll

// method 2) TORTOISE AND HARE ALGO

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
prrof->let initial distance between fast and slow pointer is d, in each step fast moves 2 step 
ans slow moves 1 step so in each iteration distance bw them reduced by 1 , at a time d-1,d-2...d-d=0
    which is at meeting point also d%1=0 ensures the meeting point.
