#  trit numbers task
#  [0,1,2] LSB formatted

import copy

# we want to go from the start of the list and try to add 1
# a value can only be 0,1 or 2
# so, if we add 1 to a 2, we overflow to the next trit
# and so on
def successor(a: list) -> list:
    success = False
    new = copy.copy(a)      # the output number
    # start from index 0, i.e the least significant trit
    i = 0

    # we will try trit by trit until the operation is successful
    while not success:
        # if we are overflowing past original size, add a new trit to the end
        if i>(len(a)-1):
            a.append(0)
            new.append(0)

        # if the value at current trit is <2 (i.e 0 or 1), we can add it it
        if a[i]<2:
            new[i]+=1
            success = True
        # if that was not posssible, we need to move to the next trit
        else:
            # reset the current trit
            new[i]=0
            i+=1

    return new

# is a less or equal to b
# go from most significant trit (MST) - reverse order
# compare trits
# at first difference, if that trit at a < that trit at b then a is smaller
def leq(a: list, b: list) -> bool:
    # first pad with 0s so both a and b have the same number of elements
    diff = abs(len(a)-len(b))
    # figure out which one is bigger, and pad the other one accordingly
    if a>b:
        # pad with 0s
        for i in range(diff):
            b.append(0)
    elif b>a:
        for i in range(diff):
            a.append(0)


    size = len(a)-1
    # we want to go in reverse order, so index will be size-i
    for i in range(len(a)):
        j = size-i  # reverse index
        # at the first sign of a's trit being < b's trit, we can say a<b
        if a[j]<b[j]:
            return True
        # at the first sign of a's trit being > b's trit, we can say a>b
        elif a[j]>b[j]:
            return False

    # if we didnt find any point at which they differed then they're equal
    return True

# take min from each trit
def tritwise_min(a: list, b: list) -> list:
    # first pad with 0s so both a and b have the same number of elements
    diff = abs(len(a)-len(b))
    # figure out which one is bigger, and pad the other one accordingly
    if a>b:
        # pad with 0s
        for i in range(diff):
            b.append(0)
    elif b>a:
        for i in range(diff):
            a.append(0)

    out = [] # our output list, the min
    # go through index of each trit one by one
    for i in range(len(a)):
        # output minimum between trit at that place in a, b
        out.append(min(a[i],b[i]))

    return out

''' I believe my algorithm runs in O(N) already
    I have just removed the padding functionality as I realised it is redundant
    since the only operations that requrie the lists to be padded are calculating min and successor
    and those functions handle padding themselves
'''
# iterative tritwise min of all lists between a and b (inclusive)
def f(a: list, b:list) -> list:
    # our output list, copy a as a start
    out = copy.copy(a) 
    # this is the successor. i.e the list we twitwise_min the output list with 
    curr_successor = successor(a)       

    # we want to keep performing the min until we reach b
    # we can do that by checking if the successor <= b
    while leq(curr_successor,b):
        # compute output: min between current output and successor in the chain
        out = tritwise_min(out,curr_successor)
        # now update the successor to be the next successor
        curr_successor = successor(curr_successor)

    return out

testA = [2,0,1]
testB = [1,1,1]
print(f(testA,testB))

