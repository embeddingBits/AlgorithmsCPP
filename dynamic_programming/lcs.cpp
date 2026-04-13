#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

int dp[MAX][MAX];

int lcs(char X[], char Y[], int m, int n) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

void traceLCS(char X[], char Y[], int m, int n) {
    char result[MAX];
    int index = dp[m][n];
    result[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            result[--index] = X[i - 1];
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout << "LCS String: " << result << endl;
}

int main() {
    char X[MAX], Y[MAX];

    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    int m = strlen(X), n = strlen(Y);
    int len = lcs(X, Y, m, n);

    cout << "\nLCS Length: " << len << endl;
    traceLCS(X, Y, m, n);

    return 0;
}
