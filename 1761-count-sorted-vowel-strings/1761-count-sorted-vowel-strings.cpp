class Solution {
public:

    bool isSorted(string &temp){
        for(int i = 0;i<temp.length()-1;++i){
            if(temp[i]>temp[i+1])return false;
        }
        return true;
    }

    int solve(vector<char>&vowels,int n,int index,string&temp){
        if(index == vowels.size())return 0;
        if(n == 0)return isSorted(temp)?1:0;
        
        temp.push_back(vowels[index]);
        int ans1 = solve(vowels,n-1,index,temp);
        temp.pop_back();

        int ans2 = solve(vowels,n,index+1,temp);

        return ans1+ans2;
    }

    int countVowelStrings(int n) {
        vector<char>vowels = {'a','e','i','o','u'};
        string temp = "";
        return solve(vowels,n,0,temp);
    }
};