#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // time complexty : O(N.logM + N.logM):-> N= number of room, M = number of meetings
        priority_queue<int, vector<int>, greater<int>> Unused_rooms;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            used_rooms;

        // keeping track of number of meetings done in each room
        vector<int> meetingCount(n, 0);
        // intialize the unused rooms first
        for (int i = 0; i < n; i++)
        {
            Unused_rooms.push(i);
        }
        // sort the meetings in ascending order acc to their start time
        sort(meetings.begin(), meetings.end());

        for (auto meet : meetings)
        {
            // getting the starting time and ending time of each meeting
            int st = meet[0];
            int en = meet[1];

            // iterating over the used room to assign the meetings
            while (!used_rooms.empty() && used_rooms.top().first <= st)
            {
                // it means that that room is not in use so we can assign a meeting to this room and
                // that means we can push it unused room
                int room = used_rooms.top().second;
                used_rooms.pop();
                Unused_rooms.push(room);
            }
            // we can say that there is a room available to assign a meeting so we assign one
            if (!Unused_rooms.empty())
            {
                int room = Unused_rooms.top();
                Unused_rooms.pop();
                used_rooms.push({en, room});
                meetingCount[room]++;
            }
            else
            {
                // if no room is available then take out a room with earliest avail time from used room
                // and update its time according to the meeting that is upcoming/ delayed
                auto [availtime, room] = used_rooms.top();
                used_rooms.pop();
                // updating the time and assigned the dealyed meeting to this earliest available room
                used_rooms.push({availtime + en - st, room});
                meetingCount[room]++;
            }
        }
        int maxCount = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (meetingCount[i] > maxCount)
            {
                ans = i;
                maxCount = meetingCount[i];
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}