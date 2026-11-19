#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())  return false;
        // only 26 possible letters
        // create a counter for them all
        int counts[26] = {};

        for(auto c:s){
            ++counts[c-'a'];
        }

        // now decrement the counter
        for(auto c:t){
            if(--counts[c-'a']<0)  return false;
        }

        return true;
    }   
};