#include <iostream>
using namespace std;

#define MAX 100

int dp[MAX][MAX];
int weights[MAX], values[MAX];

int knapsack(int n, int capacity) {
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][capacity];
}

void printSelectedItems(int n, int capacity) {
    cout << "\nSelected Items:" << endl;
    int w = capacity;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "  Item " << i
                 << " | Weight: " << weights[i - 1]
                 << " | Value: "  << values[i - 1] << endl;
            w -= weights[i - 1];
        }
    }
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    cout << "Enter each item (weight value):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> weights[i] >> values[i];
    }

    int maxVal = knapsack(n, capacity);
    cout << "\nMaximum Value: " << maxVal << endl;
    printSelectedItems(n, capacity);

    return 0;
}
