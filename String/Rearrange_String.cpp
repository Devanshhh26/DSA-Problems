
// https://leetcode.com/problems/reorganize-string/description/

#include <iostream>
using namespace std;

int main()
{
    string s = "aab";
    int hash[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i] - 'a']++;
    }
    int most_freq = -999999;
    char most_freq_char;
    for (int i = 0; i < 26; i++)                // finding the most frequent character and its frequency
    {
        if (hash[i] > most_freq)
        {
            most_freq = hash[i];
            most_freq_char = i + 'a';
        }
    }
    int index = 0;
    while (most_freq > 0 && index < s.length())         // placing the most frequent character with a gap of 1 in between them
    {
        s[index] = most_freq_char;
        most_freq--;
        index = index + 2;
    }
    if (most_freq != 0)                                 // in case if no possible solution exist
    {
        cout << "";
        return 0;
    }
    hash[most_freq_char - 'a'] = 0;                     // deleting the record of most frequent character from the hash table
    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0)
        {
            index = index >= s.size() ? 1 : index;         // if index is out of bound the call reset it to 1 else if it is inbound place the next character in that position
            s[index] = i + 'a';
            hash[i]--;
            index += 2;
        }
    }
    cout << s;
    return 0;
}