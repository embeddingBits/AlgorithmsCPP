#include <bits/stdc++.h>
using namespace std;

void naiveSearch(char text[], char pattern[])
{
      int n = strlen(text);
      int m = strlen(pattern);
      bool found = false;

      for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++) {
                  if (text[i+j] != pattern[j]) {
                        break;
                  }
            }
            if (j == m) {
                  cout << "Pattern found at index " << i << endl;
                  found = true;
            }
      }
      if (!found)
            cout << "Pattern is not found at any index of the string" << endl;
}

int main()
{
      char text[] = "AABAACAADAABAABA";
      char pattern[] = "AABA";
      naiveSearch(text, pattern);
      return 0;
}
