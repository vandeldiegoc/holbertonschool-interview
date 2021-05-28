#!/usr/bin/python3
"""module"""


def rotate_2d_matrix(matrix):
    """ matrix, rotate it 90 degrees clockwise"""
    f = len(matrix)
    c = len(matrix[0])
    resul = []
    for y in range(c):
        new_y = []
        for x in reversed(range(f)):
            new_y.append(matrix[x][y])
        resul.append(new_y)
    matrix[:] = resul
