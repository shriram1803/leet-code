class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int stones = accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> pq(piles.begin(), piles.end());
        while(!pq.empty() and k-- > 0) {
            int val = pq.top(); pq.pop();
            stones -= val / 2;
            pq.push(val - val / 2);
        }
        return stones;
    }
};