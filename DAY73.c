#include <stdio.h>
#include <string.h>

char firstNonRepeatingChar(const char *s) {
    int freq[26] = {0};  // frequency of each lowercase letter

    // Count frequencies
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Find first non-repeating
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';  // if none found
}

int main() {
    char s[100];
    scanf("%s", s);

    char result = firstNonRepeatingChar(s);
    printf("%c\n", result);

    return 0;
}
