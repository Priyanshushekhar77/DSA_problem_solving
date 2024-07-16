Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> mp;
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *newnode = new Node(curr->val);
        temp->next = newnode;
        mp[curr] = newnode;
        curr = curr->next;
        temp = temp->next;
    }
    curr = head;
    temp = dummy->next;
    while (curr != NULL)
    {
        if (curr->random != NULL)
        {
            temp->random = mp[curr->random];
        }
        temp = temp->next;
        curr = curr->next;
    }
    return dummy->next;
}