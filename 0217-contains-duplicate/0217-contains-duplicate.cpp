#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;
        for(auto num:nums){
            if(!seen.insert(num).second)  
                return true;
        }
        return false;
    }
};