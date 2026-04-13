#include <bits/stdc++.h>
using namespace std;

#define d 256
#define q 101

void rabinKarpSearch(char text[], char pattern[])
{
      int n = strlen(text);
      int m = strlen(pattern);
      int h = 1;
      int p = 0;
      int t = 0;
      bool found = false;

      for (int i = 0; i < m - 1; i++) {
            h = (h * d) % q;
      }

      for (int i = 0; i < m; i++) {
            p = (d * p + pattern[i]) % q;
            t = (d * t + text[i]) % q;
      }

      for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++) {
                  if (text[i+j] != pattern[j]) {
                        found = true;
                        break;
                  }
            }
            if (j == m) {
                  cout << "Pattern found at index " << i << endl;
            }
      }

      if (!found)
            cout << "Pattern not found";
}

int main()
{
      char text[] = "AABAACAADAABAABA";
      char pattern[] = "AABA";
      rabinKarpSearch(text, pattern);
      return 0;
}
