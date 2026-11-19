#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // get distance frome each num to target, check if element matches a distance
        std::unordered_map<int,int> dists;
        int index = 0;
        for(int num:nums){
            // try to find a match from elements already in table
            auto it = dists.find(num);
            if(it!=dists.end()){
                return {it->second,index};
            }
            // if we didnt find a match, then insert this one
            dists.try_emplace(target-num,index);
            ++index;
        }
        return {};
    }
};