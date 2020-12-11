#!/usr/bin/python3
'''module'''


def canUnlockAll(boxes):
    """ funtion that determines if all the boxes can be opened """
    openbox = [0]
    for key in openbox:
        for box in boxes[key]:
            if box not in openbox and box < len(boxes):
                openbox.append(box)
    if len(openbox) == len(boxes):
        return(True)
    else:
        return(False)
