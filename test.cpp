#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>

using namespace std;

vector<pair<string, int>> solution(vector<string> &apiList, vector<int> &rateLimits, vector<int> &defaultLimits, vector<pair<string, int>> &requests)
{
    unordered_map<string, pair<int, int>> apiRateLimits; // {API -> {limit, interval}}
    unordered_map<string, queue<int>> apiRequests;
    map<string, int> deniedRequestsCount;

    // Map each API to its specific rate limit and interval
    for (int i = 0; i < apiList.size(); i++)
    {
        apiRateLimits[apiList[i]] = {rateLimits[i], defaultLimits[i]};
    }

    // Process each request
    for (auto &request : requests)
    {
        string api = request.first;
        int timestamp = request.second;

        int limit = (apiRateLimits.find(api) != apiRateLimits.end()) ? apiRateLimits[api].first : defaultLimits[0];
        int interval = (apiRateLimits.find(api) != apiRateLimits.end()) ? apiRateLimits[api].second : defaultLimits[1];

        // Add the request to the queue for the specific API
        queue<int> &q = apiRequests[api];

        // Remove requests from the queue that are out of the rate limit window
        while (!q.empty() && q.front() <= timestamp - interval)
        {
            q.pop();
        }

        // Add the current request's timestamp to the queue
        if (q.size() < limit)
        {
            q.push(timestamp);
        }
        else
        {
            // If the request exceeds the rate limit, count it as denied
            deniedRequestsCount[api]++;
        }
    }

    // Convert the map to a vector and return it
    vector<pair<string, int>> result;
    for (const auto &entry : deniedRequestsCount)
    {
        result.push_back(entry);
    }

    return result;
}

int main()
{
    vector<string> apiList = {"type1", "type2"};
    vector<int> rateLimits = {5, 2};     // Rate limits for type1 and type2 respectively
    vector<int> defaultLimits = {1, 10}; // Default limit and interval
    vector<pair<string, int>> requests = {{"type1", 1}, {"type1", 2}, {"type1", 3}, {"type1", 11}, {"type1", 12}, {"type2", 1}, {"type2", 2}, {"type2", 6}, {"type2", 5}, {"type3", 1}, {"type4", 9}, {"type4", 14}};

    vector<pair<string, int>> result = solution(apiList, rateLimits, defaultLimits, requests);

    cout << "APIs that were rate-limited and denied request counts: " << endl;
    for (auto &entry : result)
    {
        cout << "[" << entry.first << "," << entry.second << "]" << endl;
    }

    return 0;
}
