#include <iostream>
using namespace std;

struct node {
    int val;
    node* link;
    node() : val(0), link(0) {};
    node(int x): val(x), link(0) {};
    node(int x, node* next): val(x), link(next) {};
};

class stack {
    node *top;
    public:
    stack() : top(0) {};
    void push(int x) {
        node *temp= new node(x, top);
        top= temp;
    }
    int pop() {
        if(top==0) {
            // pop operation not possible
            return -1;
        }
        int x= top->val;
        top= top->link;
        return x;
    }
    int peek() {
        return top->val;
    }
};


int main () {
    int x= 10;
    stack s;
    while(x) {
        cout<<"Enter"<<endl;
        cout<<"1 to push"<<endl;
        cout<<"2 to pop"<<endl;
        cout<<"3 to peek"<<endl;
        cout<<"0 to exit"<<endl;
        cin>>x;
        switch (x) {
            case 0:
                cout<<"Program Terminated"<<endl;
                break;
            
            case 1:
                int n;
                cout<<"Enter value\t";
                cin>>n;
                s.push(n);
                break;

            case 2:
                cout<<"You have popped "<<s.pop()<<endl;
                break;
            
            case 3:
                cout<<"The element on top is "<<s.peek()<<endl;
                break;
            
            default:
                cout<<"Please enter a correct choice"<<endl;
                break;
        }
    }
    return 0;
}
