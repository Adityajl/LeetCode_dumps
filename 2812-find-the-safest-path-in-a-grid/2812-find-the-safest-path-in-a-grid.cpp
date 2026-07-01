class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if (dist[nr][nc] != -1) continue;

                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }

        vector<vector<int>> best(n, vector<int>(n, -1));
        priority_queue<pair<int, pair<int,int>>> pq;
        best[0][0] = dist[0][0];
        pq.push({best[0][0], {0, 0}});

        while (!pq.empty()) {
            auto [safe, cell] = pq.top();
            auto [r, c] = cell;
            pq.pop();

            if (r == n - 1 && c == n - 1) return safe;
            if (safe < best[r][c]) continue;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                int nextSafe = min(safe, dist[nr][nc]);
                if (nextSafe > best[nr][nc]) {
                    best[nr][nc] = nextSafe;
                    pq.push({nextSafe, {nr, nc}});
                }
            }
        }

        return 0;
    }
};