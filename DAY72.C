#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int seen[26];   // track first occurrence index of each character
    for (int i = 0; i < 26; i++) seen[i] = -1;

    int n = strlen(s);
    char result = -1;
    int minIndex = n;  // track smallest second occurrence index

    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (seen[c] == -1) {
            seen[c] = i;  // first time seeing this character
        } else {
            // second occurrence found
            if (i < minIndex) {
                minIndex = i;
                result = s[i];
            }
        }
    }

    if (result == -1) {
        printf("-1\n");
    } else {
        printf("%c\n", result);
    }

    return 0;
}