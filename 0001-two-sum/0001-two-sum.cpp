#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // get distance frome each num to target, check if element matches a distance
        std::unordered_map<int,int> dists;
        int index = 0;
        for(int num:nums){
            // try to find a match from elements already 
            if(dists.contains(num)){
                return std::vector<int>{dists.at(num),index};
            }
            // if we didnt find a matching dista
            dists.try_emplace(target-num,index);
            ++index;
        }
        return std::vector<int>{0};
    }
};