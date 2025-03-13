// 3306-CountSubstringsContainingEveryVowelandKConsonantsII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "3306.h"
#include <unordered_map>

constexpr bool isVowel(const char ch) {
    return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'i';
}
void countRange(const std::string& word, const int pos, const int len,
    int& cons, std::unordered_map<char, int>& vows) {
    int i = pos;
    while (i < pos + len) {
        auto& ch = word[i];
        if (isVowel(ch))
            vows[ch]++;
        else
            cons++;

        i++;
    }
}

bool checkCondition(const std::string& word, const int pos, const int len,
    int k, int& cons, std::unordered_map<char, int>& vows) {
    if (cons > k /* || len - vow < k*/)
        return false;

    if (vows.size() != 5 || cons != k)
        return false;

    for (auto& it : vows) {
        if (it.second < 1)
            return false;
    }

    return true;
}

long long countOfSubstrings(string word, int k) {

    if (k + 5 > word.length())
        return 0;

    long long counter = 0;
    int pos = 0;
    int window = 5 + k;
    int len = window;

    auto curRangeCons = 0;
    std::unordered_map<char, int> curRangeVows;

    countRange(word, pos, len, curRangeCons, curRangeVows);

    auto firstRangeCons = curRangeCons;
    std::unordered_map<char, int> firstRangeVows = curRangeVows;

    while (pos < word.length()) {

        if (checkCondition(word, pos, len, k, curRangeCons, curRangeVows)) {
            counter++;
        }

        len++;

        if (curRangeCons > k || pos + len > word.length()) {

            pos++;
            len = window;

            auto lostIndex = pos - 1;
            auto lostCh = word[lostIndex];
            if (isVowel(lostCh))
                firstRangeVows[lostCh]--;
            else
                firstRangeCons--;

            auto newIndex = pos + len - 1;
            auto newCh = word[newIndex];
            if (isVowel(newCh))
                firstRangeVows[newCh]++;
            else
                firstRangeCons++;

            curRangeCons = firstRangeCons;
            curRangeVows = firstRangeVows;

            if (word.length() - pos < window)
                return counter;
        }
        else {
            auto last = pos + len - 1;
            const auto& ch = word[last];
            if (isVowel(ch))
                curRangeVows[ch]++;
            else
                curRangeCons++;
        }
    }

    return counter;
}