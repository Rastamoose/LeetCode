'''Most Frequent Integer
Given an integer array nums, return the integer that appears most frequently. 
If multiple integers have the same highest frequency, return the smallest one.
'''

from math import inf

nums = [4,2,4,2,3]

def most_frequent(nums: list[int]) -> int:
    counter = {}

    # collect frequency of each digit in dictionary
    for num in nums:
        # this whole block can be replaced with 
        # counter[num] = counter.get(num,0)+1
        if num in counter.keys():
            counter[num] += 1
        else:
            counter[num] = 1

    # find the largest out of our dict
    largest = nums[0]
    for key in counter:
        # if its same size, then we want to fetch the smaller key
        if (counter[key] > counter[largest]) or (
            counter[key]==counter[largest] and key<largest):
            largest = key


    return largest

print(most_frequent(nums))
