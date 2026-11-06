''' First Unique Character
Given a string s containing only lowercase English letters, return the index of the first character that appears exactly once. 
If none exists, return -1.
'''

# 

def first_unique(s: str) -> int:
    count = {}

    for c in s:
        count[c] = count.get(c,0) + 1
    
    for i, c in enumerate(s):
        if count[c]==1:
            return i

    return -1


inp = "aabb"
print(first_unique(inp))