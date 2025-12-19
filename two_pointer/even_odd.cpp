#include <bits/stdc++.h>
using namespace std;

void segregateEvenOdd(vector<int>& arr) {
    int i = 0;  // next position for even

    for (int j = 0; j < arr.size(); j++) {
        if (arr[j] % 2 == 0) {
            int temp = arr[j];    //swap(arr[i],arr[j]) this will destroy the order

            // shift elements right
            for (int k = j; k > i; k--) {
                arr[k] = arr[k - 1];
            }

            arr[i] = temp;
            i++;
        }
    }
}

int main() {
    vector<int> arr = {3, 8, 5, 12, 7, 6};
    segregateEvenOdd(arr);

    for (int x : arr)
        cout << x << " ";
}