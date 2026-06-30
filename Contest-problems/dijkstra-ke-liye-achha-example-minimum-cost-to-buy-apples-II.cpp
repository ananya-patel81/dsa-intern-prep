class Solution {
public:
    using ll = long long;
    const ll INF = 4e18;

    vector<long long> dijkstra(int src,
                               vector<vector<pair<int,ll>>> &graph) {
        int n = graph.size();
        vector<ll> dist(n, INF);

        priority_queue<pair<ll,int>,
                       vector<pair<ll,int>>,
                       greater<pair<ll,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u]) continue;

            for (auto &[v, w] : graph[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    vector<int> minCost(int n,vector<int>& prices,
                                  vector<vector<int>>& roads) {

        

        vector<vector<pair<int,ll>>> normal(n), taxi(n);

        for (auto &e : roads) {
            int u = e[0];
            int v = e[1];
            ll cost = e[2];
            ll tax = e[3];

            normal[u].push_back({v, cost});
            normal[v].push_back({u, cost});

            taxi[u].push_back({v, cost * tax});
            taxi[v].push_back({u, cost * tax});
        }

        vector<ll> ans(n, INF);

        for (int shop = 0; shop < n; shop++) {

            vector<ll> dNormal = dijkstra(shop, normal);
            vector<ll> dTaxi   = dijkstra(shop, taxi);

            for (int i = 0; i < n; i++) {
                ans[i] = min(ans[i],
                             (ll)prices[shop] +
                             dNormal[i] +
                             dTaxi[i]);
            }
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = (int)ans[i];

        return res;
    }
};
