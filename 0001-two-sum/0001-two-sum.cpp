#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // get distance frome each num to target
        std::unordered_map<int,int> dists;
        int index = 0;
        for(int num:nums){
            dists.try_emplace(target-num,index);
            ++index;
        }
        // then check if any num matches that distance
        index = 0;
        for(int num:nums){
            if(dists.contains(num) && dists.at(num)!=index){
                return std::vector<int>{dists.at(num),index};
            }
            ++index;
        }
        return std::vector<int>{0};
    }
};