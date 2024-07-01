// MEMORY LIMIT EXCEEDED CODE BUT WILL WORK FOR SURE */
class Solution {
public:
    vector<int> f(vector<int>& nums, int index, int last,
                map<pair<int, int>, vector<int>>& mp) {
        if (index == nums.size() - 1) {
            if (last == -1 || nums[index] > nums[last]) {
                return {index};
            }
            return {};
        }

        if (mp.find({index, last}) != mp.end()) {
            return mp[{index, last}];
        }

        /* not choosing the index */
        vector<int> notchoose = f(nums, index + 1, last,mp);

        vector<int> choose;class Solution {
public:
    pair<int, string> f(vector<int>& nums, int index, int last,
                        vector<vector<pair<int, string>>>& dp) {
        if (index == nums.size()) {
            return {0, ""};
        }

        if (dp[index][last + 1].first != -1) {
            return dp[index][last + 1];
        }

        /* not choosing the index */
        pair<int, string> notchoose = f(nums, index + 1, last, dp);

        pair<int, string> choose = {0, ""};

        /* choosing the index */
        if (last == -1 || nums[last] < nums[index]) {
            pair<int, string> result = f(nums, index + 1, index, dp);
            choose = {1 + result.first, "-" + to_string(index) + result.second};
        }

        if (choose.first >= notchoose.first) {
            dp[index][last + 1] = choose;
        } else {
            dp[index][last + 1] = notchoose;
        }

        return dp[index][last + 1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<pair<int, string>>> dp(
            n, vector<pair<int, string>>(n + 1, {-1, ""}));

        pair<int, string> answer = f(nums, 0, -1, dp);

        cout << answer.second << endl;

        return answer.first;
    }
};

        /* choosing the index */
        if (last == -1 || nums[last] < nums[index]) {
            choose.push_back(index);
            vector<int> result = f(nums, index + 1, index,mp);
            choose.insert(choose.end(), result.begin(), result.end());
        }

        if (choose.size() >= notchoose.size())
            return mp[{index, last}] = choose;

        return mp[{index, last}] = notchoose;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        map<pair<int, int>, vector<int>> mp;
        vector<int> answer = f(nums, 0, -1, mp);

        for (auto it : answer) {
            cout << it << " ";
        }
        cout << endl;

        return answer.size();
    }
};