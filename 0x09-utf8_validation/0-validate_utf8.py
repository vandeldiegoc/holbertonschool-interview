#!/usr/bin/python3
"""moddule"""


def validUTF8(data):
    """method that determines if a given data
        set represents a valid UTF-8 encoding."""
    n_bytes = 0

    mask1 = 1 << 7

    mask2 = 1 << 6
    for num in data:

        mask = 1 << 7
        if n_bytes == 0:
            while mask & num:
                n_bytes += 1
                mask = mask >> 1

            if n_bytes == 0:
                continue

            if n_bytes == 1 or n_bytes > 4:
                return False
        else:

            if not (num & mask1 and not (num & mask2)):
                return False
        n_bytes -= 1

    if n_bytes == 0:
        return True
    else:
        return False
