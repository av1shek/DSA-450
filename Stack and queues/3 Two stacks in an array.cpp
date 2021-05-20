#include<iostream>
using namespace std;

template<typename T>
class stack
{
    int topp1;
    int topp2;
    int cap;
public:

    T* arr;
    stack()
    {
        cap = 100;
        topp1 = -1;
        topp1 = cap;
        arr = new T[cap];
    }
    stack(int cap)
    {
        this->cap = cap;
        topp1 = -1;
        topp2 = cap;
        arr = new T[cap];
    }
    void push1(T val)
    {
        if(topp1+1==topp2)
        {
            cout << "Stack1 is full " << endl;
            return;
        }
        topp1++;
        arr[topp1]=val;
        return;
    }
    void push2(T val)
    {
        if(topp1+1==topp2)
        {
            cout << "Stack2 is full " << endl;
            return;
        }
        topp2--;
        arr[topp2]=val;
        return;
    }

    T pop1()
    {
        if(topp1==-1)
        {
            cout << "stack1 is empty" << endl;
            return NULL;
        }
        return arr[topp1--];
    }
    T pop2()
    {
        if(topp2==cap)
        {
            cout << "stack2 is empty" << endl;
            return NULL;
        }
        return arr[topp2++];
    }
    T top1()
    {
        if(topp1==-1)
        {
            cout << "stack is empty" << endl;
            return NULL;
        }
        return arr[topp1];
    }
    T top2()
    {
        if(topp2==cap)
        {
            cout << "stack2 is empty" << endl;
            return NULL;
        }
        return arr[topp2];
    }
    bool empty1() { return topp1==-1;}
    bool empty2() { return topp2==cap;}
    int size1() {return topp1+1;}
    int size2() {return cap - topp2;}

};
int main()
{
    stack<int> s(9);
    for(int i=0;i<10;i++){
       if(i%2) s.push1(i);
       else s.push2(i);
    }
    while(!s.empty1())
    {
        cout << s.top1() << " ";
        s.pop1();
    }
    cout << endl;
     while(!s.empty2())
    {
        cout << s.top2() << " ";
        s.pop2();
    }
    return 0;
}
