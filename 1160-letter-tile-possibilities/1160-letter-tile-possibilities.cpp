class Solution {
public:
    int numTilePossibilities(string tiles) {
        const int n = tiles.size();
        sort(tiles.begin(), tiles.end());
        vector<bool> visited(n);
        int res = 0;
        string tmp;
        numTilePossibilities(tmp, tiles, n, visited, res);
        return res;
    }
    void numTilePossibilities(string& tmp, const string& tiles, const int n, vector<bool>& visited, int& res)
    {
        if (!tmp.empty())
            ++ res;
        bitset<26> bs;
        for (int i = 0; i < n; ++ i)
        {
            if (visited[i])
                continue;
            if (bs.test(tiles[i] - 'A'))
                continue;
            visited[i] = true;
            tmp.push_back(tiles[i]);
            bs.set(tiles[i] - 'A');
            numTilePossibilities(tmp, tiles, n, visited, res);
            visited[i] = false;
            tmp.pop_back();
        }
    }
};