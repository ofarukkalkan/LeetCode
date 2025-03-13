#include "13-RomanToInteger.h"
int romanToInt(std::string s) {
    int val = 0;
    char prev = 0;
    for (auto& c : s) {
        switch (c) {
        case 'I':
            val += 1;
            break;
        case 'V':
            if (prev == 'I')
                val += 3;
            else
                val += 5;
            break;
        case 'X':
            if (prev == 'I')
                val += 8;
            else
                val += 10;
            break;
        case 'L':
            if (prev == 'X')
                val += 30;
            else
                val += 50;
            break;
        case 'C':
            if (prev == 'X')
                val += 80;
            else
                val += 100;
            break;
        case 'D':
            if (prev == 'C')
                val += 300;
            else
                val += 500;
            break;
        case 'M':
            if (prev == 'C')
                val += 800;
            else
                val += 1000;
            break;
        }
        prev = c;
    }
    return val;
}
