''' Pair Sum
Given an integer array nums and an integer target, return True if there are two distinct indices whose values sum to target. 
Otherwise, return False.
You may not use the same array position twice.
Equal values at different positions are allowed.
'''

# need to find two distinct values in array who sum to a target

# make dict with distance_to_target: element
# then go through elements again and see if they are distance to target

# SOLUTION IS OPTIMAL BUT SHOULD BE DONE WITH A SET INSTEAD - ALSO HAS O(1) 

nums = [3, 5]
target = 6

def has_pair_sum(nums: list[int], target: int) -> bool:
    dists = {}  ## distance: index
    
    for i in range(len(nums)):
        val = nums[i]
        # INCORRECT: dists[abs(target-val)] = i  # should just be target-val
        dists[target-val] = i

    #now iterate again to see if any of the values match with distance
    for i in range(len(nums)):
        val = nums[i]
        if val in dists and dists[val]!=i:
            return True

    return False

print(has_pair_sum(nums, target))