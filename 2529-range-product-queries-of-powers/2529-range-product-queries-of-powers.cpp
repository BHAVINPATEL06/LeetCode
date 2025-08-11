class Solution {
public:
    // Tere bhai ne khud se kiya hai
    // Easily ho gya

    long long int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        vector<int> ans(queries.size());

        while (n > 0) {
            for (int i = 0; i < n; i++) {
                if (pow(2, i) == n) {
                    powers.push_back(pow(2, i));
                    n = n - pow(2, i);
                    break;
                } else if (pow(2, i) > n) {
                    powers.push_back(pow(2, i - 1));
                    n = n - pow(2, i - 1);
                    break;
                }
            }
        }
        reverse(powers.begin(), powers.end());

        for (int i = 0; i < queries.size(); i++) {
            int left = queries[i][0];
            int right = queries[i][1];

            int temp = 1;
            for (int j = left; j <= right; j++) {
                temp = (temp % mod * powers[j] % mod) % mod;
            }
            ans[i] = abs(temp % mod);
        }
        return ans;
    }
};