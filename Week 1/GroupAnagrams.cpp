/*
Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
All inputs will be in lowercase.
The order of your output does not matter.
*/

class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            string str = strs[i]; // on sorting , all anagram strings give a unique key.
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(str);
        }
        vector<vector<string>>ans;
        map<string,vector<string>>::iterator it; // here we are using iterator as we are printing the map and iterator is the way to traverse a map.
        for(it = mp.begin();it!=mp.end();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
        
    }
};
