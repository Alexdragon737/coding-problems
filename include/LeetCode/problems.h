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
        int romanToInt(std::string s) 
        {
            int num = 0;
            std::map<char,int> numerals = {
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
        bool containsDuplicate(std::vector<int>& nums) 
        {
            std::map<int,bool> mapsol;
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
        std::vector<std::string> fizzBuzz(int n) 
        {
            std::vector<std::string> solution;
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
                else solution.push_back(std::to_string(i));
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
        int removeElement(std::vector<int>& nums, int val) 
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
        int searchInsert(std::vector<int>& nums, int target) 
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

        // Problem: https://leetcode.com/problems/running-sum-of-1d-array/
        std::vector<int> runningSum(std::vector<int>& nums){
            std::vector<int> runner(nums);
            for(int i=1;i<nums.size();i++)
            {
                runner[i] += runner[i-1];
            }
            return runner;
        }

        // Problem: https://leetcode.com/problems/richest-customer-wealth/
        int maximumWealth(std::vector<std::vector<int>>& accounts){
            int maxSum = 0;
            for(int i=0;i<accounts.size();i++)
            {
                int localSum = 0;
                for(int j=0;j<accounts[i].size();j++)
                    localSum += accounts[i][j];
                if(localSum > maxSum)
                    maxSum = localSum;
            }
            return maxSum;
        }

        // Problem: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
        int numberOfSteps(int num){
            int steps = 0;
            while(num != 0)
            {
                if(num % 2 == 0)
                    num /= 2;
                else num--;
                steps++;
            }
            return steps;
        }

        // Problem: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/
        int strStr(std::string haystack, std::string needle) {
            return haystack.find(needle);
        }

        // Problem: https://leetcode.com/problems/valid-palindrome/description/
        // TODO: If I remember, maybe I'll try to solve this in a more efficient way. At the very least I need to understand some other solutions
        std::string toLowerCase(std::string& s){
            for(int i=0;i<s.length();i++)
                if(s[i] >= 65 && s[i] <= 90)
                    s[i] += 32;
            return s;
        }

        std::string removeNonAlpha(std::string& s) {
	        int len = s.length(), i = 0;
	        while (i<len)
	        	if (!isalnum(s[i]))
	        	{
	        		s.erase(i, 1);
	        		len--;
	        	}
	        	else i++;
	        return s;
        }

        bool isPalindrome(std::string s) {
        bool result = true;
        s = toLowerCase(s);
        s = removeNonAlpha(s);
        for(int i=0;i<s.length()/2;i++)
        {
            if(s[i] == s[s.length()-i-1])
                continue;
            else{
                result = false;
                break;
            }
        }
        return result;
    }

        // Problem: https://leetcode.com/problems/valid-anagram/description/
        bool isAnagram(std::string s, std::string t) {
        std::map<char,int> freq;
        for(auto c : s)
        {
            freq[c]++;
        }

        for(auto c : t)
        {
            freq[c]--;
        }

        for(auto it : freq)
        {
            if(it.second != 0)
                return false;
        }
        return true;
    }

        
    };
}