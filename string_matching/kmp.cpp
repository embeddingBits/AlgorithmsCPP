#include <iostream>
#include <cstring>
using namespace std;

void computeLPS(char pattern[], int m, int lps[]) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[1000];
    bool found = false;

    computeLPS(pattern, m, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            found = true;
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    if (!found)
        cout << "Pattern not found." << endl;
}

int main() {
    char text[1000], pattern[1000];

    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    KMPSearch(text, pattern);
    return 0;
}
