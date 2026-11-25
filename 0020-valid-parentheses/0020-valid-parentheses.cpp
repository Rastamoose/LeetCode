#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        std::vector<char> stack;
        //std::unordered_map<char,char> pairs = {{'(',')'},{'{','}'},{'[',']'}};

        for(char& c:s){
            if(c=='(')
                stack.push_back(')');
            else if(c=='[')
                stack.push_back(']');
            else if(c=='{')
                stack.push_back('}');
            else{
                if(stack.empty()) return false;
                if(c==stack.back()){
                    stack.pop_back();
                }
                else{
                    return false;
                }
            }
        }
        return stack.empty();
    }
};