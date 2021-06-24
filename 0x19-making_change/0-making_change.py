#!/usr/bin/python3
"""module"""


def makeChange(coins, total):
    """Given a pile of coins of different
       values, determine the fewest number
       of coins needed to meet a given amount total """
    new = []
    n = len(coins)
    coins.sort()
    coins = sorted(coins, reverse=True)
    if total <= 0:
        return 0
    for i in range(n):
        j = i
        
        while (j < n):

            if sum(new) == total:
                return len(new)
            if sum(new) < total:
                new.append(coins[j])
                
                if sum(coins) % total == 0:
                    j += 1
                    continue


            if sum(new) > total:
                new.pop()
                j += 1
                continue
    return -1  
