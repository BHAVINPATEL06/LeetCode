class Solution {
public:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;

        return false;
    }

    bool isValid(string word) {
        unordered_map<char, int> mapp;
        if (word.length() < 3)
            return false;

        for (int i = 0; i < word.size(); i++) {
            if(word[i] <= '9' && word[i]>='0')continue;

            if ((word[i] >= 'A' && word[i] <= 'Z') ||
                (word[i] >= 'a' && word[i] <= 'z'))
                mapp[word[i]]++;
            else
                return false;
        }
        // if (mapp.size() < 3)
        //     return false;

        bool ans1 = false;
        bool ans2 = false;
        for (auto a : mapp) {
            if (isVowel(a.first))
                ans1 = true;
            if (!isVowel(a.first))
                ans2 = true;
        }

        return ans1 && ans2;
    }
};