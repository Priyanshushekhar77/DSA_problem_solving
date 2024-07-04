/*
You are given a Singly Linked List of N nodes such that each node represents a single digit.
Your task is to return a node 'X', where 'X' represents the head of the Linked List storing the digits of the sum(most significant digit at the head) formed by adding the 1st half and 2nd half of the given Linked List.
Note:

1. When N is odd consider the middle element to be part of 1st half.

2. The sum should not contain any leading zero, except the number 0 itself.
For Example:
Given Linked List: 1-2-3-4-5-5-6

First half: 1-2-3-4
Second half: 5-5-6

Output Linked List: 1-7-9-0 = (1234 + 556 = 1790)

=>Approach
Find the middle of the linked list and split it into two halves.
Reverse the first and second half.
Add the two halves digit by digit.
reverse the resultant ll which comes after adding
Construct the resulting linked list.
*/

// reverse the ll
Node *reversell(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *currnext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = currnext;
    }
    return prev;
}

// adding two ll
Node *addtwoll(Node *l1, Node *l2)
{
    Node *dummy = new Node(-1);
    Node *p = l1;
    Node *q = l2;
    Node *temp = dummy;
    int carry = 0;
    while (p != NULL || q != NULL)
    {
        // if p or q is null than deferencing them will cause a runtime error so we need to check if p and q are not null before accessing their data members
        int x = (p != NULL) ? p->data : 0;
        int y = (q != NULL) ? q->data : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        // making the resultant ll
        temp->next = new Node(sum % 10);
        temp = temp->next;
        // check either part is empty or not than move the pointer to next port
        if (p != NULL)
            p = p->next;
        if (q != NULL)
            q = q->next;
    }
    // if any quotient remained
    if (carry > 0)
        temp->next = new Node(carry);

    return dummy->next;
}

Node *addFirstAndSecondHalf(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    // find the middle of ll
    Node *slow = head;
    Node *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // split the ll into two halves
    Node *firsthalf = head;
    Node *sechalf = slow->next;
    slow->next = NULL; // break the connection

    // reverse the first and sec half
    firsthalf = reversell(firsthalf);
    sechalf = reversell(sechalf);
    // adding both halves
    Node *findsum = addtwoll(firsthalf, sechalf);
    // reversing the resultant ll
    findsum = reversell(findsum);
    // handling zero which is at starting point
    while (findsum != NULL && findsum->data == 0)
    {
        findsum = findsum->next;
    }
    // if findsum doesnot contain any thing like for t.c(0,0,0) than simply return the 0 as answer
    return findsum ? findsum : new Node(0);
}
