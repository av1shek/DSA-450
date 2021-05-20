#include<iostream>
using namespace std;

template<typename T>
struct node{
    T data;
    node* prev, *next;
    node() {prev=NULL; next=NULL;  }
    node(T val){prev=NULL; next=NULL; data=val;}

};

template<typename T>
class stack
{
    node<T>* topp;
    node<T>* mid;
    int cnt;
public:

    stack() {cnt=0; topp = NULL; }
    void push(T val)
    {
        cnt++;
        if(topp == NULL){
            topp = new node<T>(val);
            mid=topp;
            return;
        }
        topp->next = new node<T>(val);
        topp->next->prev = topp;
        topp = topp->next;
        if(cnt%2==0){mid = mid->next;}
        return;
    }
    T pop()
    {
        if(topp==NULL)
        {
            cout << "stack is empty" << endl;
            return NULL;
        }
        cnt--;
        T data = topp->data;
        topp = topp->prev;
        if(cnt%2==1){mid = mid->prev;}
        return data;
    }
    bool empty(){return topp==NULL;}
    T top() {return topp->data;}
    T getMid()
    {
        if(mid==NULL)
        {
            cout << "stack is empty" << endl;
            return NULL;
        }
        return mid->data;
    }
};

int main()
{
    stack<int> s;
    for(int i=0;i<10;i++)
    {
        s.push(i);
        cout<<"m = "<< s.getMid() << " ";
    }
    cout << endl;
    while(!s.empty())
    {
        //cout << s.top() << " ";
        cout<<"m = "<< s.getMid() << " ";
        s.pop();
    }
    return 0;
}
