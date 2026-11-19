#include <vector>
#include <set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> seen;
        for(auto num:nums){
            if(seen.contains(num))  
                return true;
            else    
                seen.insert(num);
            
        }
        return false;
    }
};