class Solution {
public:
    bool isPalindrome(string s) {
        std::vector<char> str;
        // convert all the lowercase
        // 65->90 uppercase
        // 97->122 lowercase
        for(char& c:s){
            if(c-'A'<26 && c-'A'>=0){
                c+=('a'-'A'); 
                str.push_back(c);
                std::cout << c;
            }else if((c-'a'<26 && c-'a'>=0) || (c-'0'<10 && c-'0'>=0)){
                str.push_back(c);
                std::cout << c;

            }
        }

        int size= str.size();
        
        for(int i=0;i<size;++i){
            int otherSide = size-i-1;
            if(str.at(i)!=str.at(otherSide))    return false;
            if((i+1)==otherSide)    return true;
        }

        return true;
    }
};