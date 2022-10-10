#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <map>

namespace LeetCode
{
    class Solution 
    {
        public:
        // Problem: https://leetcode.com/problems/roman-to-integer/
        int romanToInt(string s) 
        {
            int num = 0;
            map<char,int> numerals = {
                {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
            };
            for(int i=0;i<s.length();i++)
            {
                if(numerals[s[i]] < numerals[s[i+1]])
                {   
                    num += numerals[s[i+1]] - numerals[s[i]];
                    i++;
                    continue;
                }
                num += numerals[s[i]];
            }
            return num;
        }

        // Problem: https://leetcode.com/problems/contains-duplicate/
        bool containsDuplicate(vector<int>& nums) 
        {
            map<int,bool> mapsol;
            for(int i=0;i<nums.size();i++)
            {
                if(mapsol.find(nums[i]) != mapsol.end())
                    return true;
                else mapsol[nums[i]] = true;
            }
            return false;
        }

        // Problem: https://leetcode.com/problems/reverse-integer/
        int reverse(int x) 
        {
            long long inverted = 0;
            while(x != 0)
            {
                int l_digit = x % 10;
                inverted = inverted*10 + l_digit;
                x /= 10;
            }
            if(inverted >= INT_MAX || inverted <= INT_MIN)
                return 0;
            return inverted;
        }

        // Problem: https://leetcode.com/problems/fizz-buzz/
        vector<string> fizzBuzz(int n) 
        {
            vector<string> solution;
            for(int i=1;i<=n;i++)
            {
                if(i%3 == 0 && i%5 !=0)
                {
                    solution.push_back("Fizz");
                    continue;
                }
                if(i%5 == 0 && i%3 != 0)
                {
                    solution.push_back("Buzz");
                    continue;
                }
                if(i%3 == 0 && i%5 == 0)
                {    
                    solution.push_back("FizzBuzz");
                    continue;
                }
                else solution.push_back(to_string(i));
            }
            return solution;
        }

        // Problem: https://leetcode.com/problems/palindrome-number/
        bool isPalindrome(int x) 
        {
            long rev_num = 0;
            int x_cpy = x;
            if(x<0)
                return false;
            while(x != 0)
            {
                int l_digit = x % 10;
                x /= 10;
                rev_num = rev_num*10 + l_digit;
            }
            if(rev_num != x_cpy)
                return false;
            return true;
        }

        // Problem: https://leetcode.com/problems/remove-element/
        int removeElement(vector<int>& nums, int val) 
        {
            int initialSize = nums.size(), cutElements = 0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i] == val)
                    cutElements++;
                else
                    nums[i-cutElements] = nums[i];
            }
            return initialSize - cutElements;
        }

        // Problem: https://leetcode.com/problems/climbing-stairs/
        int climbStairs(int n) 
        {
            int first = 1, second = 2, num;

            if(n <= 0 || n == 1 || n == 2)
                return n;
            else for(int i=2;i<n;i++)
            {
                num = first + second;
                first = second;
                second = num;
            }
            return num;
        }

        // Problem: https://leetcode.com/problems/search-insert-position/
        int searchInsert(vector<int>& nums, int target) 
        {
            int low = 0, high = nums.size();
            while(low < high)
            {
                int mid = (low+high)/2;
                if(nums[mid] == target)
                    return mid;
                else if(nums[mid] < target)
                    low = mid + 1;
                else high = mid;
            }
            return low;
        }
    };
}