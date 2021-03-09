#include <map>
#include <vector>
#include <string>
using namespace std;

//  Map ver:
class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        map<char, int> originMap;
        map<char, int> charsMap;
        for (auto it = chars.begin(); it != chars.end(); it++)
        {
            if (charsMap.end() == charsMap.find(*it))
            {
                charsMap[*it] = 1;
                originMap[*it] = 1;
            }
            else
            {
                charsMap[*it]++;
                originMap[*it]++;
            }
        }
        int sum = 0;
        bool isIn = false;
        for (int i = 0; i < words.size(); i++)
        {
            isIn = true;
            for (auto it = words[i].begin(); it != words[i].end(); it++)
            {
                if (charsMap.end() == charsMap.find(*it) || charsMap[*it] == 0)
                {
                    isIn = false;
                    break;
                }
                else
                {
                    charsMap[*it]--;
                }
            }
            if (isIn)
                sum += words[i].size();
            charsMap = originMap;
        }
        return sum;
    }
};

//  Array Ver:
class Solution2
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int chMap[26];
        for (int i = 0; i < 26; i++)
            chMap[i] = 0;
        for (auto it = chars.begin(); it != chars.end(); it++)
        {
            chMap[*it - 'a']++;
        }
        int sum = 0;
        bool isIn = false;
        int wdMap[26];
        for (int i = 0; i < 26; i++)
            wdMap[i] = 0;
        for (int i = 0; i < words.size(); i++)
        {
            isIn = true;
            for (auto it = words[i].begin(); it != words[i].end(); it++)
            {
                wdMap[*it - 'a']++;
                if (wdMap[*it - 'a'] > chMap[*it - 'a'])
                    break;
            }
            for (int i = 0; i < 26; i++)
            {
                if (wdMap[i] > chMap[i])
                    isIn = false;
                wdMap[i] = 0;
            }
            if (isIn)
                sum += words[i].size();
        }
        return sum;
    }
};