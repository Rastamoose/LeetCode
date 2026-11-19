#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())    return false;
        // put all letters of first string + occurances in a map
        // then check second string against that
        std::unordered_map<char,int> letters;
        for(auto c:s){
            auto it = letters.find(c);
            if(it==letters.end()){
                letters.emplace(c,1);
            }else{
                ++it->second;
            }
        }

        for(auto c:t){
            auto it = letters.find(c);
            if(it==letters.end() || it->second==0)   
                return false;
            else
                --it->second;
        }
        return true;
    }
};