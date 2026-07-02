class Solution {
public:

    bool check(int threshold,
               int n,
               vector<vector<pair<int,int>>> &adj,
               int source,
               int target,
               int k)
    {
        deque<int> dq;

        vector<int> dist(n, INT_MAX);

        dist[source] = 0;

        dq.push_front(source);

        while (!dq.empty())
        {
            int u = dq.front();
            dq.pop_front();

            for (auto &[v, w] : adj[u])
            {
                int cost = (w > threshold);

                if (dist[u] + cost < dist[v])
                {
                    dist[v] = dist[u] + cost;

                    if (cost == 0)
                        dq.push_front(v);
                    else
                        dq.push_back(v);
                }
            }
        }

        return dist[target] <= k;
    }

    int minimumThreshold(int n,
                         vector<vector<int>>& edges,
                         int source,
                         int target,
                         int k)
    {
        if (source == target)
            return 0;

        vector<vector<pair<int,int>>> adj(n);

        int mx = 0;

        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});

            mx = max(mx, e[2]);
        }

        // connectivity check
        if (!check(mx, n, adj, source, target, edges.size()))
            return -1;

        int lo = 0;
        int hi = mx;

        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (check(mid, n, adj, source, target, k))
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};
