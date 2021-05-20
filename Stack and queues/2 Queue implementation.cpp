#include<iostream>
using namespace std;

template<typename T>
class queue
{
    int frontt;
    int rear;
    int cap;
    T *arr;
public:
    queue()
    {
        frontt = rear = -1;
        cap = 100;
        arr = new T[cap];
    }
    queue(int cap)
    {
        frontt = rear = -1;
        this->cap = cap;
        arr = new T[cap];
    }
    bool empty() { return frontt==-1; }
    bool full() { return (rear+1)%cap == frontt; }

    void push(T val)
    {
        if(full())
        {
            cout <<"queue is full" << endl;
            return;
        }
        rear = (rear+1)%cap;
        arr[rear] = val;
        if(frontt == -1)
            frontt = rear;
    }

    T pop()
    {
        if(empty())
        {
            cout << "queue is empty" << endl;
            return NULL;
        }
        T data = arr[frontt];
        if(frontt == rear)
            frontt = rear = -1;
        else
            frontt = (frontt+1)%cap;
        return data;
    }
    T front()
    {
        if(empty())
        {
            cout << "queue is empty" << endl;
            return NULL;
        }
        return arr[frontt];
    }
};


int main()
{
    queue<double> q;
    for(int i=0;i<10;i++) q.push(i*1.01);
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
