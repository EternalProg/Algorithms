const int ZERO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    using p_int = pair<int, int>;
    vector<p_int> adj[105];
    vector<p_int> ans;

    bool static cmp(const p_int p1, const p_int p2) {
        if (p1.first != p2.first)
            return p1.first < p2.first;

        return p1.second > p2.second;
    }

    void dijkstra(int src, int n, int distanceThreshold) {
        priority_queue<p_int, vector<p_int>, greater<p_int>> pq;
        vector<int> distance(n + 1, INT_MAX);

        distance[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int prev = pq.top().second;
            int prevDist = pq.top().first;
            pq.pop();

            for (auto it : adj[prev]) {
                int next = it.first;
                int nextDist = it.second;
                if (distance[next] > distance[prev] + nextDist) {
                    distance[next] = distance[prev] + nextDist;
                    pq.push({distance[next], next});
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i != src && distance[i] <= distanceThreshold)
                cnt++;
        }

        ans.push_back({cnt, src});
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        for (int i = 0; i < n; i++) {
            dijkstra(i, n, distanceThreshold);
        }

        sort(ans.begin(), ans.end(), cmp);

        return ans[0].second;
    }
};
