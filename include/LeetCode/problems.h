#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>

namespace LeetCode
{
    // LeetCode style linked list node
    struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

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

        // Problem: https://leetcode.com/problems/merge-sorted-array/
        void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
            for(int i=0;i<n;i++)
                nums1[m+i] = nums2[i];

            std::sort(nums1.begin(),nums1.end());
        }

        // Problem: https://leetcode.com/problems/majority-element/description/
        int majorityElement(std::vector<int>& nums) {
        std::map<int,int> apparitions;
        int max = 0, ans = 0;
        for(auto x : nums)
        {
            if(apparitions.find(x) == apparitions.end())
                apparitions[x] = 1;
            else apparitions[x]++;
        }

        for(auto it : apparitions)
        {
            if(it.second > max)
            {
                max = it.second;
                ans = it.first;
            }
        }   
        return ans; 
    }

         /*
            Problem: https://leetcode.com/problems/pascals-triangle/

            Props to community for the solution.
            This uses the combinatorial formula C(n,k) = C(n-1,k-1) + C(n-1,k)

            I really wanted to implement this using the binomial theorem, 
            but factorials are a pain to implement without having a BigInt library,
            since the regular data types are only able to cover up to n=15.
        */
        std::vector<std::vector<int>> generate(int numRows) {
            std::vector<std::vector<int>> ans;
            for(int i=0;i<numRows;i++)
            {
                std::vector<int> ansRow(i+1,1);
                for(int j=1;j<i;j++)
                {
                    ansRow[j] = ans[i-1][j-1] + ans[i-1][j];
                }
                ans.push_back(ansRow);
            }
            return ans;
        }

        // Problem: https://leetcode.com/problems/number-of-1-bits/
        int hammingWeight(uint32_t n) {
            uint32_t zeroes = 0;

            /*
                We just apply the basic binary conversion algorithm.
                When we find a '1' in the binary representation, the counter increments.
            */
            while(n != 0)
            {
                if(n % 2 != 0)
                    zeroes++;
                n = n/2;
            }
            return zeroes;
        }

        // Problem: https://leetcode.com/problems/merge-two-sorted-lists/
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /*
            When we're working with linked lists, and we have to
            return the head of the new linked list, the easiest
            approach is to just use two nodes.
            One will be modified, the other will stay as is.
        */
        ListNode *list3 = new ListNode(), *dummy = list3;
        
        // This is what we need to do if both lists are not empty
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val < list2->val){
                dummy->next = list1;
                list1 = list1->next;
            }
            else{
                dummy->next = list2;
                list2 = list2->next;
            }
            dummy = dummy->next;
        }

        // What we do after we reach the end of the linked list
        if(list1 != NULL) dummy->next = list1;
        if(list2 != NULL) dummy->next = list2;

        // Extra step to avoid leaks
        return dummy = list3->next;
        delete list3;
        return dummy;
    }

        
    };
}