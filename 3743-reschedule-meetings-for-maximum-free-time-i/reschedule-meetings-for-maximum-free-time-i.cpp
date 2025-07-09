class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps(1,startTime[0]);
        
        for(int i = 1; i < startTime.size(); i++){
            gaps.push_back(startTime[i] - endTime[i-1]);
        }
        gaps.push_back(eventTime - endTime.back());
        int curr_sum = 0;
        int maxFreeTime = 0;
        for(int i = 0; i < gaps.size(); i++){
            curr_sum += gaps[i] - ((i >= k+1)?gaps[i-(k+1)]:0);
            maxFreeTime = max(maxFreeTime,curr_sum);
        }
        return maxFreeTime;
    }
};