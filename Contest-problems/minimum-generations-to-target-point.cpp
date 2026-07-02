class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {

        // Store unique points
        set<vector<int>> current;

        for (auto &p : points)
            current.insert(p);

        // Target already exists
        if (current.count(target))
            return 0;

        int generation = 0;

        while (true) {

            vector<vector<int>> existing(current.begin(), current.end());
            set<vector<int>> newPoints;

            int n = existing.size();

            // Generate all possible new points
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {

                    vector<int> mid(3);

                    for (int k = 0; k < 3; k++) {
                        mid[k] = (existing[i][k] + existing[j][k]) / 2;
                    }

                    // Only consider points never seen before
                    if (!current.count(mid))
                        newPoints.insert(mid);
                }
            }

            // No new point can ever be generated
            if (newPoints.empty())
                return -1;

            generation++;

            // Add new points
            for (auto &p : newPoints) {

                if (p == target)
                    return generation;

                current.insert(p);
            }
        }

        return -1;
    }
};
