''' Balanced Brackets
Given a string s containing only the characters (, ), [, ], {, and }, return whether it is valid.
A string is valid when:
- Every opening bracket has a closing bracket of the same type.
- Brackets close in the correct nesting order.
- No closing bracket appears without a corresponding opening bracket.
The empty string is valid.
'''


#e.g ([{}]) ()[]
# false e.g ([)], {{
# go through, if it is an opener add to the stack
# if it is not an opener then it must match the last opener -> pop last opener
# stack must be completely cleared by the end

s = "{{"

pairs = {'{':'}', '(':')', '[':']'}

def valid_brackets(s: str) -> bool:
    stack = []

    for c in s:
        if c not in pairs:
            if (not stack) or (c != pairs[stack.pop()]):
                return False
        else:
            stack.append(c)

    return len(stack)==0

print(valid_brackets(s))