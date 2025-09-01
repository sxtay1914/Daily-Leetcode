class Solution {o
//TC: O(N*word[i].length*word.length)
//SC: O(N)
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //my firs apprach was going up and keeping track of prev
        //but we can go down
        vector<int> dp(s.size(), -1);
        return dfs(s.size()-1, s, wordDict, dp);
    }
private:
    //O(N)
    bool dfs(int i, string& s, vector<string>& wordDict, vector<int>& dp){
        if (i<0){
            return true;
        }
        if (dp[i]!=-1){
            return dp[i];
        }
        //O(word[i].length*word.length)
        for (string& word: wordDict){
            int l = word.size();
            if (i+1-l<0){
                continue;
            }
            if (s.substr(i+1-l, l)==word){
                if (dfs(i-l, s, wordDict, dp))
                    return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
};