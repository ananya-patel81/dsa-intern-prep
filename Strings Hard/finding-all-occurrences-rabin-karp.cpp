vector<int> rabinKarpAll(string text, string pattern) {
    using ull = unsigned long long;

    int n = text.size();
    int m = pattern.size();

    vector<int> ans;
    if (m > n) return ans;

    const ull BASE = 131;

    ull patternHash = 0;
    ull windowHash = 0;
    ull highestPower = 1;

    for (int i = 0; i < m; i++) {
        patternHash = patternHash * BASE + pattern[i];
        windowHash = windowHash * BASE + text[i];

        if (i < m - 1)
            highestPower *= BASE;
    }

    for (int start = 0; start <= n - m; start++) {

        if (windowHash == patternHash) {

            bool match = true;

            for (int j = 0; j < m; j++) {
                if (text[start + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            if (match)
                ans.push_back(start);
        }

        if (start < n - m) {
            windowHash -=
                (ull)(unsigned char)text[start] * highestPower;

            windowHash *= BASE;

            windowHash +=
                (unsigned char)text[start + m];
        }
    }

    return ans;
}
