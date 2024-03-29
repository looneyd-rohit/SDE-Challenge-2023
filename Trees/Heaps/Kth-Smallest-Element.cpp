// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        // smallest element --> max heap is required
        priority_queue<int> maxheap;
        for(int i=l; i<=r; i++){
            maxheap.push(arr[i]);
            if(maxheap.size()>k) maxheap.pop();
        }
        return maxheap.top();
    }
};