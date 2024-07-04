
/*
Given a doubly linked list of n elements. Your task is to reverse the doubly linked list in-place.

Example 1:

Input:
LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3
Example 2:

Input:
LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75
*/

Node *reverseDLL(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    Node *temp = head;
    Node *back = NULL;
    while (temp)
    {
        Node *curr = temp->next;
        temp->next = back;
        temp->prev = curr;
        back = temp;
        temp = curr;
    }
    return back;
}