void QueueStack :: push(int x)
{
        q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if(q1.size()==0) return -1;
        while(q1.size()>1) { q2.push(q1.front());  q1.pop();}
        int data  = q1.front();   q1.pop();
        swap(q1, q2);
        return data;
}