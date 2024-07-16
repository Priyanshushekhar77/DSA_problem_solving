/*
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [3,2,1,6,5,4,9,8,7,10]

steps->
1.find the kthnode and if kthnode is null and prev exist than join(prev->next=temp) and break loop;
2.keep track of nextnode(nextnode=kthnode->next) of kthnode for further kth reversal and break the linkage kthnode->next=null;
3.reverse it reversell(temp) ,in case of first reversal if(temp==head) make head=kthnode  else prev->next=kthnode;
4. make prev equals to temp and temp equals to nextnode
*/

// reverse the ll
Node *reversell(Node *head)
{
    Node *prev = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        Node *curr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
    }
    return prev;
}

// get kth element
Node *kthll(Node *temp, int k)
{
    k -= 1;
    while (temp != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}
Node *kReverse(Node *head, int k)
{
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        Node *kthnode = kthll(temp, k);
        // agar kthnode null mila i.e 10-> NULL
        if (kthnode == NULL)
        {
            if (prev)
                prev->next = temp; // 7->10
            break;
        }
        // next node of kthnode
        Node *nextnode = kthnode->next;
        // break the link at kthnode
        kthnode->next = NULL;
        // rever the ll from kth position
        reversell(temp);
        // first time kth reversal
        if (temp == head)
        {
            head = kthnode; // change the head
        }
        // otherwiae join prev and nextnode i.e 1->6 and 4->9
        else
        {
            prev->next = kthnode;
        }
        // make prev to kthnode and temp to nextnode for further revrsal and join
        prev = temp;
        temp = nextnode;
    }
    return head;
}

/*
Time Complexity: O(2N) The time complexity consists of actions of reversing segments of K and finding the Kth node which operates in linear time. Thus, O(N) + O(N) = O(2N), which simplifies to O(N).

Space Complexity: O(1) The space complexity is O(1) as the algorithm operates in place without any additional space requirements.
*/