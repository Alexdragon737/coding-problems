#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <map>

typedef unsigned long long ull;

namespace Codewars
{
    // Problem: https://www.codewars.com/kata/52597aa56021e91c93000cb0/cpp
    std::vector<int> move_zeroes(const std::vector<int>& input) 
    {
        std::vector<int> movedZeroes;
        for(unsigned long i=0;i<input.size();i++)
        {
            if(input[i] != 0)
                movedZeroes.push_back(input[i]);
        }
        for(unsigned long i=0;i<input.size();i++)
        {
            if(input[i] == 0)
                movedZeroes.push_back(input[i]);
        }
        return movedZeroes;
    }

    // Problem: https://www.codewars.com/kata/513e08acc600c94f01000001/cpp
    class RGBToHex
    {
      public:
      static std::string rgb(int r, int g, int b)
      {
        std::string result;
        result.append(toHex(&r));
        result.append(toHex(&g));
        result.append(toHex(&b));
        return result;
      };
      static std::string toHex(int* n)
      {
        std::string result;
        int c_n = *n;

        // Check edge cases
        if(*n < 0)
          return "00";
        else if(*n > 255)
          return "FF";

        // Check normal cases
        if(*n==0)
          return "00";
        else if(*n > 0 && *n <=15)
          result += '0';
        while(*n != 0)
          {
            int temp = *n % 16;
            if(temp < 10)
                result += temp+48;
            else result += temp + 55;
            *n /= 16;
          }
        if(c_n>=16)
          reverse(result.begin(),result.end());

        return result;
      };
    };

    // Problem: https://www.codewars.com/kata/5541f58a944b85ce6d00006a
    class ProdFib
    {
    public:
        static std::vector<ull> productFib(ull prod);
    };

    std::vector<ull> ProdFib::productFib(ull prod)
    {
        std::vector<ull> fib = {0,1}, res;
        int i=0;
        ull next = fib[i]+fib[i+1];
        while(next < prod)
        {
          next = fib[i]+fib[i+1];
          fib.push_back(next);
          i++;
        }
        for(ull i=0;i<fib.size()-1;i++)
        {
          if(fib[i]*fib[i+1] == prod)
          {
            res.push_back(fib[i]);
            res.push_back(fib[i+1]);
            res.push_back(true);
            break;
          }
          else if(fib[i]*fib[i+1] > prod)
          {
            res.push_back(fib[i]);
            res.push_back(fib[i+1]);
            res.push_back(false);
            break;
          }
        }
      return res;
    }

    // Problem: https://www.codewars.com/kata/530e15517bc88ac656000716/cpp
    std::string rot13(std::string msg)
    {
        for(unsigned int i=0;i<msg.length();i++)
            if(msg[i] >= 97 && msg[i] <= 122)
                msg[i] = ((msg[i]-97+13)%26+97);
            else if(msg[i] >= 65 && msg[i] <= 90) 
                msg[i] = ((msg[i]-65+13)%26+65);
        return msg;
    }

    // Problem: https://www.codewars.com/kata/57ea70aa5500adfe8a000110/cpp
    class Kata
    {
    public:
        std::vector<int> foldArray(std::vector<int> array, int runs)
        {
          std::vector<int> fold;
            for(int i=0;i<runs;i++)
            {
              int isize = array.size();
              for(int j=0;j<isize/2;j++)
              {
                array[j] += array[isize-j-1];
                array.pop_back();
              }
            }  
          return array;
        }
    };

    // Part 1 of problem: https://www.codewars.com/kata/53697be005f803751e0015aa/cpp
    std::string encode(const std::string &str) 
    {
        std::map<char,char> encoder = {{'a','1'},{'e','2'},{'i','3'},{'o','4'},{'u','5'}};
        std::string strCopy = str;

        for(unsigned long i=0;i<strCopy.length();i++)
        {
            auto search = encoder.find(strCopy[i]);
            if(search != encoder.end())
                strCopy[i] = encoder[strCopy[i]];
        }
        return strCopy;
    }

    // Part 2 of problem: https://www.codewars.com/kata/53697be005f803751e0015aa/cpp
    std::string decode(const std::string &str)
    {
        std::map<char,char> decoder = {{'1','a'},{'2','e'},{'3','i'},{'4','o'},{'5','u'}};
        std::string strCopy = str;

        for(unsigned long i=0;i<strCopy.length();i++)
        {
            auto search = decoder.find(strCopy[i]);
            if(search != decoder.end())
                strCopy[i] = decoder[strCopy[i]];
        }
        return strCopy;
    }

    // Problem: https://www.codewars.com/kata/526571aae218b8ee490006f4/cpp
    unsigned int countBits(unsigned long long n)
    {
        std::vector<int> nToBin;
        unsigned long long sum=0;
        while(n > 0)
        {
            int temp = n%2;
            n /= 2;
            if(temp == 1)
                sum += 1;
            nToBin.push_back(temp);
        }
        return sum;
    }

    //Problem: https://www.codewars.com/kata/534d2f5b5371ecf8d2000a08/cpp
    using namespace std;
    vector<vector<int>> multiplication_table(int n)
    {
        std::vector<std::vector<int>> a;
        for (int i = 0; i < n; i++)
        {
            std::vector<int> a1;
            for (int j = 0; j < n; j++)
            {
                int x = (i + 1) * (j + 1);
                a1.push_back(x);
            }
            a.push_back(a1);
        }
        return a;
    }

    // Problem: https://www.codewars.com/kata/526571aae218b8ee490006f4/cpp
    unsigned int countBits(unsigned long long n)
    {
      std::vector<int> nToBin;
      unsigned long long sum=0;
      while(n > 0)
      {
        int temp = n%2;
        n /= 2;
        if(temp == 1)
          sum += 1;
        nToBin.push_back(temp);
      }
      return sum;
    }

    // Problem: https://www.codewars.com/kata/58f5c63f1e26ecda7e000029
    std::vector<std::string> wave(std::string y)
    {
        std::vector<std::string> x;
        for(unsigned long i = 0; i<y.length();i++)
        {
          if(y[i] != ' ')
          {  
            y[i] -= 32;
            x.push_back(y);
            y[i] += 32;
           }
          else continue;
        }
        return x;
    }
}