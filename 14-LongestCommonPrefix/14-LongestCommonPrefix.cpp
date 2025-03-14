// 14-LongestCommonPrefix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "14-LongestCommonPrefix.h"
string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 1)
        return strs[0];

    string cPre = "";
    size_t chIndex = 0;
    auto it = strs.begin();
    while (true)
    {
        char c = (*it)[chIndex];
        it++;
        while (it != strs.end())
        {
            if (chIndex >= it->length())
                return cPre;

            if ((*it)[chIndex] != c)
                return cPre;

            it++;
        }

        cPre += c;
        it = strs.begin();
        chIndex++;
    }

    return cPre;
}