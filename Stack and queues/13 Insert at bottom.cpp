#include<bits/stdc++.h>
using namespace std;

void insertAtEnd(int x, stack<int> &s)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }

    int temp = s.top(); s.pop();
    insertAtEnd(x, s);
    s.push(temp);
    return;
}
int main()
{
    stack<int> s;
    for(int i=0;i<5;i++) s.push(i);
    insertAtEnd(10, s);
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
