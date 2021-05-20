#include<iostream>
using namespace std;


template<typename T>
class stack
{
    T *arr;
    int *topp;
    int *next;
    int n, k, nextAvl;
public:

    stack(int n, int k)
    {
        this->n = n;
        this->k = k;
        nextAvl = 0;

        arr = new T[n];
        topp = new int[k];
        next = new int[n];

        for(int i=0;i<n;i++) next[i] = i+1;
        next[n-1] = -1;
        for(int i=0;i<k;i++) topp[i] = -1;

    }

    bool isFull() { return nextAvl==-1; }
    bool empty(int idx) { return topp[idx]==-1; }

    void push(T val, int idx)
    {
        if(isFull())
        {
            cout << "stack is full" << endl;
            return;
        }

        int dataIndx = nextAvl;
        nextAvl = next[dataIndx];
        next[dataIndx] = topp[idx];
        topp[idx] = dataIndx;

        arr[dataIndx] = val;
    }

    T pop(int idx)
    {
        if(empty(idx))
        {
            cout << "stack " << idx << " is empty" << endl;
            return NULL;
        }

        int dataIndx = topp[idx];
        topp[idx] = next[dataIndx];
        next[dataIndx] = nextAvl;
        nextAvl = dataIndx;
        return arr[dataIndx];
    }

};

int main()
{
    stack<int> s(100, 3);

    for(int i=0;i<20;i++){
        s.push(i, i%3);
    }

    while(!s.empty(0)) cout << s.pop(0) << " ";
    cout << endl;

    while(!s.empty(1)) cout << s.pop(1) << " ";
    cout << endl;

    while(!s.empty(2)) cout << s.pop(2) << " ";
    cout << endl;
    return 0;
}
