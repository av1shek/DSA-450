#include<bits/stdc++.h>
using namespace std;

void insert(int x, stack<int> &s)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }

    if(x > s.top())
    {
        s.push(x);
    }
    else
    {
        int y = s.top();s.pop();
        insert(x, s);
        s.push(y);
    }
    return;
}

void sortStack(stack<int> &s)
{
    if(s.empty()) return;
    int x = s.top(); s.pop();
    sortStack(s);
    insert( x, s);
}

int main()
{
    int arr[] = {1,5,3,2,21,67,12};
    stack<int> s;
    for(int i=0;i<7;i++) s.push(arr[i]);
    sortStack(s);
    for(int i=0;i<7;i++) {cout << s.top() << " "; s.pop();}
    return 0;
}
