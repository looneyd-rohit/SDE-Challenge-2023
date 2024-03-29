// Leetcode 1539
class Solution
{
public:
    bool isPossible(vector<int> &arr, int k, int num)
    {
        int cnt = 0;
        bool isPresent = false;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > num)
            {
                break;
            }
            cnt++;
            if (arr[i] == num)
            {
                isPresent = true;
            }
        }
        // cnt --> gives the count of the nos. <= num
        if (isPresent)
        {
            cnt--;
            return (num - 1 - cnt) >= (k);
        }
        else
        {
            return (num - 1 - cnt) >= (k - 1);
        }
    }
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 1, high = 2069;
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            bool flag = isPossible(arr, k, mid);
            // cout<<mid<<" : "<<flag<<endl;
            if (flag)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

// Optimized: O(Log(N))
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (k <= arr[0] - 1)
            return k;
        if (k > arr.back() - n)
            return (arr.back() + k - (arr.back() - n));
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            int missingTillNow = arr[mid] - (mid + 1);
            if (missingTillNow >= k)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        int missingTillNow = arr[high] - (high + 1);
        int extra = k - missingTillNow;
        return arr[high] + extra;
    }
};
