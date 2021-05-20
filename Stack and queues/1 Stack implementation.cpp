#include<iostream>
using namespace std;

template<typename T>
class stack
{
    int topp;
    int cap;
public:

    T* arr;
    stack()
    {
        topp = -1;
        cap = 100;
        arr = new T[cap];
    }
    stack(int cap)
    {
        topp = -1;
        this->cap = cap;
        arr = new T[cap];
    }
    void push(T val)
    {
        if(topp==cap)
        {
            cout << "Stack is full " << endl;
            return;
        }
        topp++;
        arr[topp]=val;
        return;
    }

    T pop()
    {
        if(topp==-1)
        {
            cout << "stack is empty" << endl;
            return NULL;
        }
        return arr[topp--];
    }
    T top()
    {
        if(topp==-1)
        {
            cout << "stack is empty" << endl;
            return NULL;
        }
        return arr[topp];
    }
    bool empty() { return topp==-1;}
    int size() {return topp+1;}

};
int main()
{
    stack<char> s;
    for(int i=0;i<10;i++) s.push('a'+i);
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
