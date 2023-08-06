#include <iostream>
using namespace std;

struct node {
    int val;
    node* link;
    node() : val(0), link(0) {};
    node(int x): val(x), link(0) {};
    node(int x, node* next): val(x), link(next) {};
};

node* create(int n);
void traverse(node *start);
void insertAtEnd(node *start, int val);
void insertAtStart(node *start, int val);
void insertInMiddle(node *prev, int val);
int deleteAtEnd(node *start);
int deleteAtStart(node *start);
int deleteInMiddle(node *prev);
node* reverse(node *start);

int main() {
    int n;
    node *start;
    cout<<"Size of Linked List\t";
    cin>>n;
    cout<<"Values of Linked List"<<endl;
    start= create(n);
    traverse(start);
    return 0;
}

node* create(int n) {
    node *start= new node(), *temp= start;
    while(n--) {
        cin>>temp->val;
        if(n>0)
            temp->link= new node();
        temp= temp->link;
    }
    return start;
}

void traverse(node *start) {
    node *temp= start;
    while(temp!=0) {
        cout<<temp->val<<' ';
        temp= temp->link;
    }
    cout<<endl;
}

void insertAtEnd(node *start, int val) {
    if(start==0) {
        start= new node(val);
        return;
    }
    node *temp= start;
    // skip to the end
    while(temp->link!=0)
        temp= temp->link;
    // create a new node and link it
    temp->link= new node(val);
}

void insertAtStart(node *start, int val) {
    // create a new node with val and attach start to it
    node *temp= new node(val, start);
    // assign it to start
    start= temp;
}

void insertInMiddle(node *prev, int val) {
    if(prev==0) {
        // insertion not possible
        return;
    }
    // save link to next in new node
    node *temp= new node(val, prev->link);
    // link it
    prev->link= temp;
}

int deleteAtEnd(node *start) {
    if(start==0) {
        // deletion not possible
        return -1;
    }
    int x;
    if(start->link==0) {
        x= start->val;
        start= 0;
        return x;
    }
    node *temp= new node;
    while(temp->link->link!=0) 
        temp= temp->link;
    x= temp->link->val;
    temp->link=0;
    return x;
}

int deleteAtStart(node *start) {
    if(start==0) {
        // deletion not possible
        return -1;
    }
    int x= start->val;
    // move start to next link
    start= start->link;
    return x;
}

int deleteInMiddle(node *prev) {
    if(prev==0 || prev->link==0) {
        // deletion not possible
        return -1;
    }
    int x= prev->link->val;
    // attach the previous node's link to next node
    prev->link= prev->link->link;
    return x;
}

node* reverse(node *start) {
    if(start==0 || start->link==0)
        return start;
    node *prev= 0, *cur= start, *next= start->link;
    while(cur!=0) {
        cur->link= prev;
        prev= cur;
        cur= next;
        if(cur!=0)
            next= cur->link;
    }
    return prev;
}
