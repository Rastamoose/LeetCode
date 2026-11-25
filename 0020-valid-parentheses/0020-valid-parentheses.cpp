#include <vector>

class Solution {
public:
    bool isValid(string s) {
        std::vector<char> stack;

        // if odd length then can't be valid
        if(s.size()%2==1)   return false;

        for(char& c:s){
            if(c=='(')
                stack.push_back(')');
            else if(c=='[')
                stack.push_back(']');
            else if(c=='{')
                stack.push_back('}');
            else{
                if(stack.empty())   return false;
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