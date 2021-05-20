#include<iostream>
using namespace std;

template<typename T>
class stack
{
    int topp;
    int cap;
public:

    T* arr;
    T minVal;
    stack()
    {
        topp = -1;
        cap = 100;
        minVal = NULL;
        arr = new T[cap];
    }
    stack(int cap)
    {
        topp = -1;
        this->cap = cap;
        minVal = NULL;
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
        if(topp == 0){
            arr[topp]=val;
            minVal = val;
        }
        else if(val >= minVal){
            arr[topp]=val;
        }
        else{
            arr[topp] = 2*val - minVal;
            minVal = val;
        }
        return;
    }

    T pop()
    {
        if(topp==-1)
        {
            cout << "stack is empty" << endl;
            return NULL;
        }
        if(arr[topp] >= minVal){
            return arr[topp--];
        }
        else{
            T data = minVal;
            minVal = 2*minVal - arr[topp];
            topp--;
            return data;
        }
    }
    T top()
    {
        if(topp==-1)
        {
            cout << "stack is empty" << endl;
            return NULL;
        }
        if(arr[topp] < minVal) return minVal;
        return arr[topp];
    }
    bool empty() { return topp==-1;}
    int size() {return topp+1;}
    T getMin()
    {
        if(empty())
        {
            cout << "stack is empty" << endl;
            return NULL;
        }
        return minVal;
    }

};
int main()
{
    stack<int> s;
    int a[] = {5,3,2,3,4,-2,3};
    for(int i=0;i<7;i++) s.push(a[i]);
    while(!s.empty())
    {
        cout<<"val = "<< s.top() << endl;
        cout<<"minVal = "<< s.getMin() << endl << endl;
        s.pop();
    }
    return 0;
}
