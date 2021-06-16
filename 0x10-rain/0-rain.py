#!/usr/bin/python3


def rain(walls):
    """calculate how many square
       units of water will be retained
       after it rains """
    if list is None:
        return 0
    n = len(walls)
    res = 0
    for i in range(1, n - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]
        for j in range(i + 1, n):
            right = max(right, walls[j])
        res = res + (min(left, right) - walls[i])
    return res
