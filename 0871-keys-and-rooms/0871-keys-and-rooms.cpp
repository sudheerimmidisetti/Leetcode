class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int> visited(n, -1);
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            visited[node] = 16;
            for (auto num : rooms[node]) {
                if (visited[num] == -1)
                    q.push(num);
            }
        }

        return (count(visited.begin(), visited.end(), -1) > 0) ? false : true;
    }
};