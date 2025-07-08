class Solution {
public:

    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')return true;

        return false;
    }

    bool isValid(string temp){
        int n = temp.length()-1;
        if(isVowel(temp[0]) && isVowel(temp[n]))return true;

        return false;
    }


    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>prefixSum(words.size()+1);
        prefixSum[0] = 0;
        vector<int>ans;

        for(int i = 0;i<words.size();i++){
            if(isValid(words[i])){
                prefixSum[i+1] = 1;
            }
        }

        for(int i = 1;i<prefixSum.size();i++){
            prefixSum[i] = prefixSum[i-1]+prefixSum[i];
        }

        for(int i = 0;i<queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];

            ans.push_back(prefixSum[right+1]-prefixSum[left]);
        }

        return ans;
    }
};