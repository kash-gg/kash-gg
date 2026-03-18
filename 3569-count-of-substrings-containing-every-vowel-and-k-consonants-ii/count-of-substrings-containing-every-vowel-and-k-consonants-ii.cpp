class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        unordered_map<char, int> a;
        int Vowel_Present = 0;
        int consonants = 0;
        long long ans = 0;
        int i = 0;
        int extra = 0;  // Tracks redundant vowels we've trimmed from the left

        for (int j = 0; j < word.size(); j++) {
            // 1. Expand the window
            if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' ||
                word[j] == 'o' || word[j] == 'u') {
                a[word[j]]++;
                if (a[word[j]] == 1) {
                    Vowel_Present++;
                }
            } else {
                consonants++;
            }

            // 2. Shrink from left if consonants exceed k
            while (consonants > k) {
                if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
                    word[i] == 'o' || word[i] == 'u') {
                    a[word[i]]--;
                    if (a[word[i]] == 0) {
                        Vowel_Present--;
                    }
                } else {
                    consonants--;
                }
                i++;
                extra = 0; // Constraints broke, so reset extra valid starts
            }

            // 3. Trim redundant vowels from the left to count all valid starting points
            // We permanently remove them and add to `extra`
            while (i < j && (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
                             word[i] == 'o' || word[i] == 'u') && a[word[i]] > 1) {
                a[word[i]]--;
                i++;
                extra++;
            }

            // 4. Count valid windows
            if (Vowel_Present == 5 && consonants == k) {
                ans += (1 + extra);
            }
        }
        return ans;
    }
};
