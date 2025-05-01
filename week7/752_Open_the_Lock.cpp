class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        queue<string> q;
        q.push("0000");
        visited.insert("0000");

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();

                if (dead.count(curr)) continue;
                if (curr == target) return steps;

                // 產生所有鄰近狀態
                for (int j = 0; j < 4; ++j) {
                    string up = curr;
                    string down = curr;

                    up[j] = (up[j] == '9') ? '0' : up[j] + 1;
                    down[j] = (down[j] == '0') ? '9' : down[j] - 1;

                    if (!visited.count(up) && !dead.count(up)) {
                        q.push(up);
                        visited.insert(up);
                    }
                    if (!visited.count(down) && !dead.count(down)) {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }

            ++steps;
        }

        return -1;
    }
};
