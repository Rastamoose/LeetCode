#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        std::vector<char> stack;
        std::unordered_map<char,char> pairs = {{'(',')'},{'{','}'},{'[',']'}};

        for(char& c:s){
            if(pairs.find(c)!=pairs.end()){
                stack.push_back(c);
            }
            else{
                if(stack.size()==0) return false;
                if(c==pairs[stack.back()]){
                    stack.pop_back();
                }
                else{
                    return false;
                }
            }
        }
        if(stack.size()==0) return true;
        else    return false;
    }
};