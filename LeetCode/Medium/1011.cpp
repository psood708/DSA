#include <bits/stdc++.h>
using namespace std;

bool weight(vector<int> &wts, int mid, int days)
{
    int n = wts.size();
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + wts[i] > mid)
        {
            cnt++;
            sum = wts[i];
        }
        else
        {
            sum += wts[i];
        }
    }
    if (cnt <= days)
        return true;
    else
        return false;
}

int shipWithinDays(vector<int> &nums, int days)
{
    int n = nums.size();
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (weight(nums, mid, days))
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = shipWithinDays(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";

    return 0;
}