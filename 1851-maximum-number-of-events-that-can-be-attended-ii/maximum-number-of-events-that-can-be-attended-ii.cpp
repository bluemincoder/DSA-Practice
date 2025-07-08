class Solution {
public:
    vector<vector<int>>dp;
    int solve(int idx,vector<vector<int>>& events, vector<int>&starts, int k){
        if(idx >= events.size() || k <= 0)return 0;
        if(dp[idx][k] != -1)return dp[idx][k];
    
        int next = upper_bound(starts.begin()+idx, starts.end(), events[idx][1])-starts.begin();
      int inc = events[idx][2] + solve(next, events, starts, k-1);
      int exc = solve(idx+1, events, starts, k);

        return dp[idx][k] = max(inc, exc);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
       dp = vector<vector<int>>(n+1, vector<int>(k+1, -1));
       vector<int>start(n,0);
       for(int i = 0; i<n; i++){
          start[i] = events[i][0];
       }
        return solve(0, events, start, k);
    }
};