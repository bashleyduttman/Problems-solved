#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    char kthCharacter(__int128 k, vector<int>& operations) {
        return findChar(k, operations, operations.size());
    }

    char findChar(__int128 k, vector<int>& operations, int ind) {
        if (ind == 0) return 'a'; // Base case: initial string is "a"

        __int128 prevLength = (__int128)1 << (ind - 1); // Length before this operation

        if (k > prevLength) { // Second half
            k -= prevLength;
            if (operations[ind - 1] == 1) return shift(findChar(k, operations, ind - 1));
        }

        return findChar(k, operations, ind - 1);
    }

    char shift(char c) { // Shifts 'z' to 'a' and others normally
        return (c == 'z') ? 'a' : (c + 1);
    }
};

// Helper function to read and print __int128
