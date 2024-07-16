/* link->https://leetcode.com/problems/intersection-of-two-linked-lists/description/
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
*/

// METHOD 1) find n=len of ll(1) - len of ll(2); then move the temp1==ll1 n times as len of ll1>ll2 than move together temp1 and temp2 and compare their value for the intersections

// method2)
ListNode *getIntersectionNode(ListNode *heada, ListNode *headb)
{
    ListNode *temp1 = heada;
    ListNode *temp2 = headb;
    if (heada == NULL || headb == NULL)
        return NULL;
    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if (temp1 == temp2)
            return temp1;
        if (temp1 == NULL)
            temp1 = headb; // after getting null start from new ll
        if (temp2 == NULL)
            temp2 = heada;
    }
    return temp1;
}

// method3) HASHMAP
ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
{
    unordered_set<ListNode *> st;
    while (head1 != NULL)
    {
        st.insert(head1);
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        if (st.find(head2) != st.end())
            return head2;
        head2 = head2->next;
    }
    return NULL;
}