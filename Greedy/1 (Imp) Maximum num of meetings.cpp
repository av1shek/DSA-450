static bool comp(pii a, pii b )
{
    if(a.second == b.second)
        return a.first == b.first;
    return (a.second < b.second);
}
int maxMeetings(int start[], int end[], int n)
{
    vector<pii> meetings;
    for(int i=0;i<n;i++)
        meetings.push_back({start[i], end[i]});
    sort(meetings.begin(), meetings.end(), comp);
    int cnt = 1;
    pii prev = meetings[0];
    for(int i=1;i<n;i++)
        if(meetings[i].first > prev.second)
        {
            prev = meetings[i];
            cnt++;
        }
    return cnt;
}