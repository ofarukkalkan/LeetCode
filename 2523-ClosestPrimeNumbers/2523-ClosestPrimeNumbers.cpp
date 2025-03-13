#include "2523-ClosestPrimeNumbers.h"
#include <iostream>
#include <vector>


std::vector<int> closestPrimes(int left, int right) {
    if (left < 2 && right < 3)
        return { -1, -1 };

    if (left == 2 && right == 3)
        return { 2, 3 };

    std::vector<int> res2;
    res2.push_back(-1);
    res2.push_back(-1);
    std::vector<int> res;
    res.reserve(2);

    if (left % 2 == 0)
        left++;
    if (right % 2 == 0)
        right--;

    int minDiff = std::numeric_limits<int>::max();

    for (int i = left; i <= right;  i += 2) {
        bool isPrime = true;

        for (int j = 2; j < i / 2; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            if (res.size() < 2)
            {
               res.push_back(i);
            }
            else
            {
                res[0] = res[1];
                res[1] = i;
            }

        }

        if (res.size() >= 2)
        {
            auto diff = res[1] - res[0];
            if (diff < minDiff)
            {
                res2[0] = res[0];
                res2[1] = res[1];
                minDiff = diff;
            }
        }
    }
    return res2;
}

int main() {

    //checkPowersOfThree(91);
    auto res = closestPrimes(84084, 407043);
   // auto res = closestPrimes(2, 3);
    std::cout << res[0] << "-" << res[1];
    return 0;
}