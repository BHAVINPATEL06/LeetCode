class TrieNode {
public:
    char val;
    unordered_map<int, TrieNode*> children;
    bool isTerminal;

    TrieNode(char data) {
        val = data;
        isTerminal = false;
    }
};

void insertIntoTrie(TrieNode* root, string temp) {
    if (temp.length() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = temp[0];
    TrieNode* child;

    if (root->children.count(ch) == 1) {
        child = root->children[ch];
    } else {
        child = new TrieNode(ch);
        root->children[ch] = child;
    }
    insertIntoTrie(child, temp.substr(1));
}

void solve(TrieNode* root, vector<string>& ans, string temp) {
    if (root->isTerminal == true) {
        ans.push_back(temp);
        return;
    }

    for (auto nbr : root->children) {
        temp.push_back(nbr.second->val);
        solve(nbr.second, ans, temp);
        temp.pop_back();
    }
    return;
}

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        for (const auto& f : folder) {
            if (ans.empty() || f.substr(0, ans.back().size()) != ans.back() ||
                f[ans.back().size()] != '/') {   
                ans.push_back(f); 
            }
        }
        return ans;
    }
};