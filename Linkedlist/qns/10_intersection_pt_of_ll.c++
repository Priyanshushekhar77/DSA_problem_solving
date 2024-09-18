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
    // if anyone of them is NULL than ints is not possible
    if (heada == NULL || headb == NULL)
        return NULL;

    while (temp1 != temp2)
    { 
        // we are moving one step ahead becz we are ignoring a first starting positipon
        temp1 = temp1->next;
        temp2 = temp2->next;
        // if equals
        if (temp1 == temp2)
            return temp1;
        if (temp1 == NULL)
            temp1 = headb; // after getting null start from new opposite ll
        if (temp2 == NULL)
            temp2 = heada;
    }
    return NULL;
}
// proof-> here if anyone t1 or t2 reaches null than we initialise them to opposite ll 
// becz let initially t1 is d-2 dis behind from t2 & if t1 reaches null than t1=headb becz to
// managing a distance he is behind from t2
//t-c->(N1+N2)
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
