class Solution {
public:
    string largestGoodInteger(string num) {

        unordered_map<char, int> mapp;

        int left = 0;
        int right = 0;
        string ans = "";
        int maxi = INT_MIN;

        while (right < 3) {
            mapp[num[right]]++;
            right++;
        }
        if (mapp.size() == 1) {
            string temp = num.substr(left, 3);
            int comp = stoi(temp);
            int check = maxi;
            maxi = max(comp, maxi);
            if (check < maxi) {
                ans = temp;
            }
        }

        while (right < num.length()) {
            mapp[num[left]]--;
            if (mapp[num[left]] == 0)
                mapp.erase(num[left]);

            mapp[num[right]]++;

            if (mapp.size() == 1) {
                string temp = num.substr(left+1, 3);
                int comp = stoi(temp);
                int check = maxi;
                maxi = max(comp, maxi);
                if (check < maxi) {
                    ans = temp;
                }
            }
            left++;
            right++;
        }

        return ans;
    }
};