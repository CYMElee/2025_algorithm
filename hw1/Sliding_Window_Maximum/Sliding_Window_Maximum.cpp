#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Method to find the maximum for each
// and every contiguous subarray of size k.
vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> res;
    deque<int> dq; // Deque to store indices of array elements

    for (int i = 0; i < n; i++) {
        // Remove elements that are out of this window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove all elements smaller than the currently
        // being added element (arr[i])
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }

        // Add current element at the rear of the deque
        dq.push_back(i);

        // If our window has hit size k, add to results
        if (i >= k - 1) {
            res.push_back(arr[dq.front()]);
        }
    }

    return res;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    // Display input values
    cout << "Input: nums = [";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "], k = " << k << endl;

    // Get output values
    vector<int> res = maxOfSubarrays(arr, k);

    // Display output values
    cout << "Output: [";
    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

