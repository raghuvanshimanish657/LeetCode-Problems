class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size();
        queue<int> q{};
        for (int i = 0; i < n; ++i) 
            if (d[i] != '.') q.push(i);
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int idx = q.front(); q.pop();
                if (d[idx] == 'R' && idx + 1 < n && d[idx + 1] == '.') {
                    if (idx + 2 < n && d[idx + 2] == 'L') {
                        d[idx + 1] = 'm';
                    }
                    else {
                        d[idx + 1] = 'R';
                        q.push(idx + 1);
                    }
                } 
                else if (d[idx] == 'L' && idx - 1 >= 0 && d[idx - 1] == '.') {
                    d[idx - 1] = 'L';
                    q.push(idx - 1);
                }
            }
        }
        for (char& ch : d)
            if (ch == 'm') ch = '.';
        return d;
    }
};