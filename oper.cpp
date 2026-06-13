// #include <stdio.h>
// int main()
// {
//     float a = 4.9;
//     float b = 5.9;
//     // int c = int(b);
//     printf("%d,%d ", a, b);
//     return 0;
// }
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

string Firstnonrepeating(string A) {
    unordered_map<char, int> count;
    queue<char> q;
    string ans = "";

    for (int i = 0; i < A.length(); i++) {
        char ch = A[i];

        // Increase count
        count[ch]++;

        // Enqueue character
        q.push(ch);

        // Check if the front character is non-repeating
        while (!q.empty() && count[q.front()] > 1) {
            q.pop();
        }

        // Update the answer
        if (!q.empty()) {
            ans.push_back(q.front());
        } else {
            ans.push_back('#'); // No non-repeating character found
        }
    }

    return ans;
}

int main() {
    string input = "aaabbbccc";
    cout << "First non-repeating characters: " << Firstnonrepeating(input) << endl;
    return 0;
}
