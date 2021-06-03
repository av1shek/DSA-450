class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int> > high;
    void insertHeap(int &x)
    {
        if(low.size()==0) { low.push(x); return; }
        if(x > low.top()) high.push(x);
        else low.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(high.size() > low.size() + 1)
        {
            low.push(high.top());
            high.pop();
        }
        else if(high.size() + 1 < low.size())
        {
            high.push(low.top());
            low.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(low.size() == high.size()) return low.empty()?0:( (low.top()+high.top())/2.0);
        else return (low.size() > high.size())? low.top():high.top(); 
    }
};