class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int t) {
        int arrival = times[t][0];
        sort(times.begin(), times.end());
        set<int> avilableSeats;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        int newSeat = 0;
        int result;
        for (int i = 0; i < times.size(); i++) {
            int seat = -1;
            while (!pq.empty() && pq.top().first <= times[i][0]) {
                seat = pq.top().second;
                pq.pop();
                avilableSeats.insert(seat);
            }
            if (avilableSeats.size() > 0) {
                seat = *(avilableSeats.begin());
                avilableSeats.erase(seat);
            } else {
                seat = newSeat++;
            }
            pq.push({times[i][1], seat});
            if (times[i][0] == arrival) {
                result = seat;
                break;
            }
        }
        return result;
    }
};
