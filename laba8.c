#include <stdio.h>
#include <string.h>
#include <ctype.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    char word[15];
    printf("Vvedit' slovo: ");
    scanf("%s", word);

    int length = strlen(word);
    int frequency[26] = {0};

    for (int i = 0; i < length; ++i) {
        word[i] = tolower(word[i]);
        frequency[word[i] - 'a']++;
    }

    unsigned long long totalAnagrams = factorial(length);

    for (int i = 0; i < 26; ++i) {
        if (frequency[i] > 1) {
            totalAnagrams /= factorial(frequency[i]);
        }
    }

    printf("Kil'kist' anagram: %llu\n", totalAnagrams);

    return 0;
}
