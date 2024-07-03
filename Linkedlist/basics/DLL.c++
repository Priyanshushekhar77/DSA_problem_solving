#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
       Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }

};

Node* convertArr2DLL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;            

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp; 
        prev = temp;       
    }
    return head;  
}


void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";  
        head = head->next;         
    }
}

Node* inserthead(Node* head, int val) {
    Node* newNode = new Node(val,head,NULL);
    head->prev=newNode;
    return newNode;
}
 
Node* insertAtTail(Node* head, int k) {
    Node* newNode = new Node(k);
    if (head == nullptr) {
        return newNode;
    }
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;

    return head;
}

//insertion at kth position
Node* insertkth(Node* head, int k,int val){
  if(k==1)return  inserthead(head,val);
  Node* temp=head;
  int cnt=0;
  while(temp){
    cnt++;
    if(cnt==k) break;
    temp=temp->next;
  }
  Node* back=temp->prev;
  Node* newnode=new Node(val,temp,back);
  back->next=newnode;
  temp->prev=newnode;
return head;
}


Node* deleteHead(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr; 
    }
    Node* orghead = head;      
    head = head->next;    
    head->prev = nullptr;   

    orghead->next = nullptr;  

    return head;          
}

Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;  
    }
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next; 
    }
    Node* newTail = tail->prev;
    newTail->next = nullptr;
    // diconnect the tail
    tail->prev = nullptr;
    
    // Free memory of the deleted node
    delete tail;  
    
    return head;
}


//delete at kth position
Node* deletekth(Node* head, int k){
    if(head==NULL) return NULL;
    int cnt=0;
    Node* temp=head;
    while(temp){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }

    Node* back=temp->prev;
    Node* front=temp->next;
    if(back==NULL && front==NULL) return NULL;
    else if(front==NULL) return deleteTail(head);
    //else if(prev==NULL) return deleteHead(head);
    back->next=front;
    front->prev=back;
    temp->next=NULL;
    temp->prev=NULL;
    delete(temp);
    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);

cout << "Doubly Linked List Initially: " << endl;
    print(head);
    cout << endl << "Doubly Linked List After Inserting at the tail with value 10: " << endl;
     // Insert a node with value 10 at the end
    head = insertAtTail(head, 10);
    print(head);

    return 0;
};