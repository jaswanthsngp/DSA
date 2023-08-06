#include <iostream>
using namespace std;

struct node {
    int val;
    node* link;
    node() : val(0), link(0) {};
    node(int x): val(x), link(0) {};
    node(int x, node* next): val(x), link(next) {};
};

class queue {
    node *start, *end;
    public:
    queue() : start(0), end(0) {};
    void push(int x) {
        node *temp= new node(x);
        if(start==0) {
            start= end= temp;
            return;
        }
        end->link= temp;
        end= end->link;
    }
    int pop() {
        if(start==0) {
            // pop operation not possible
            return -1;
        }
        int x= start->val;
        if(start==end) {
            start=end=0;
        } else {
            start= start->link;
        }
        return x;
    }
};

int main() {
    int x= 10;
    queue q;
    while(x) {
        cout<<"Enter"<<endl;
        cout<<"1 to push"<<endl;
        cout<<"2 to pop"<<endl;
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
                q.push(n);
                break;

            case 2:
                cout<<"You have popped "<<q.pop()<<endl;
                break;
            
            default:
                cout<<"Please enter a correct choice"<<endl;
                break;
        }
    }
    return 0;
}
