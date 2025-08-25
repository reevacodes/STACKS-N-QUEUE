// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> slidingWindowMax(vector<int> &nums, int k)
// {
//   int n = nums.size();
//   vector<int> windowMax;
//   for (int i = 0; i < n - k + 1; i++)
//   {
//     int maxi = nums[i];
//     for (int j = 0; j < i + k; j++)
//     {
//       maxi = max(maxi, nums[j]);
//     }
//     windowMax.push_back(maxi);
//   }
//   return windowMax;
// }

// int main()
// {
//   vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
//   int k = 3;
//   vector<int> ans = slidingWindowMax(nums, k);
//   for (auto a : ans)
//   {
//     cout << a << " ";
//   }
//   return 0;
// }

// OPTIMAL

#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMax(vector<int> &nums, int k)
{
  deque<int> dq; // stores indices
  vector<int> res;

  for (int i = 0; i < nums.size(); i++)
  {
    // Remove indices that are out of the current window
    while (!dq.empty() && dq.front() <= i - k)
    {
      dq.pop_front();
    }

    // Remove elements smaller than current from the back
    while (!dq.empty() && nums[dq.back()] < nums[i])
    {
      dq.pop_back();
    }

    dq.push_back(i);

    // Record max for current window
    if (i >= k - 1)
    {
      res.push_back(nums[dq.front()]);
    }
  }

  return res;
}

int main()
{
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;

  vector<int> ans = slidingWindowMax(nums, k);
  for (int x : ans)
  {
    cout << x << " ";
  }
  return 0;
}
