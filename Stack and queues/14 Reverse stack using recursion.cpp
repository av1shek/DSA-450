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

void reverseStack(stack<int> &s)
{
    if(s.empty()) return;
    int x = s.top(); s.pop();
    reverseStack(s);
    insertAtEnd( x, s);
}

int main()
{
    stack<int> s;
    for(int i=0;i<5;i++) s.push(i);
    reverseStack(s);
    for(int i=0;i<5;i++) {cout << s.top() << " "; s.pop();}
    return 0;
}
