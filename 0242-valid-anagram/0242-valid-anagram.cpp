#include <unordered_map>

class Solution {
public:
    // bool isAnagram(string s, string t) {
    //     if(s.size()!=t.size())    return false;
    //     // put all letters of first string + occurances in a map
    //     // then check second string against that
    //     std::unordered_map<char,int> letters;
    //     for(auto c:s){
    //         ++letters[c];
    //     }

    //     for(auto c:t){
    //         auto it = letters.find(c);
    //         if(it==letters.end() || it->second==0)   
    //             return false;
    //         else
    //             --it->second;
    //     }
    //     return true;
    // }

    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())  return false;
        // only 26 possible letters
        // create a counter for them all
        int counts[26] = {0};

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