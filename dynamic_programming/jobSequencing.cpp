#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

struct Job {
    char id;
    int deadline;
    int profit;
};

Job jobs[MAX];

void sortByProfit(int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (jobs[j].profit < jobs[j + 1].profit) {
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
}

void jobSequencing(int n) {
    sortByProfit(n);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    bool slot[MAX];
    char result[MAX];
    memset(slot, false, sizeof(slot));

    int totalProfit = 0, jobCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
        }
    }

    cout << "\nSelected Jobs: ";
    for (int i = 0; i < maxDeadline; i++)
        if (slot[i]) cout << result[i] << " ";
    cout << endl;
    cout << "Total Profit: " << totalProfit << endl;
    cout << "Number of Jobs Selected: " << jobCount << endl;
}

int main() {
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    cout << "Enter each job (id deadline profit):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ": ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    jobSequencing(n);
    return 0;
}
