string chooseandswap(string a)
{
    set<char> s;
    int n = a.size();
    for (char ch : a) s.insert(ch);
    
    for (int i = 0; i < n; i++) 
    {
        s.erase(a[i]);
        if (s.empty()) break;
        if (*s.begin() < a[i]) {
            char ol = a[i], ne = *s.begin();
            for (int j = 0; j < n; j++) {
                if (a[j] == ol) a[j] = ne;
                else if (a[j] == ne) a[j] = ol;
            }
            break;
        }
    }
    return a;
}