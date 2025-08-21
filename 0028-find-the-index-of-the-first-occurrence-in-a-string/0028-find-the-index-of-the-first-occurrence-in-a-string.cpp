class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle) == string::npos)return -1;
        if(haystack.length()<needle.length())return -1;

        map<int,string>mapp;

        for(int k = 0;k<=haystack.length()-needle.length();k++){
            string temp = haystack.substr(k,needle.length());
            mapp[k] = temp;
        }

        for(auto a:mapp){
            if(a.second == needle)return a.first;
            // cout<<a.first << " " << a.second << endl;
        }
        return -1;
    }
};