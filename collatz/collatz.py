#!/bin/python3

import math
import os
import random
import re
import sys

def fillPath(n,paths,limit):
    if n == 1:
        paths[1] = 1
    
    if n < limit and paths[n]:
        return paths[n]
    else:
        if n%2:
            if n < limit:
                paths[n] = fillPath(3*n+1,paths,limit) + 1
                return paths[n]
            else:
                return fillPath(3*n+1,paths,limit) + 1
        else:
            if n < limit:
                paths[n] = fillPath(n//2,paths,limit) + 1
                return paths[n]
            else:
                return fillPath(n//2,paths,limit) + 1

if __name__ == '__main__':
    jumps = [None for i in range(100000000)]
    # inputFile = "./brianfry.in"
    # f = open(inputFile, 'r')
    # for line in f.readlines():
    ij = input().rstrip().split()
    while ij != "":
        # ij= line.rstrip().split()
        
        i = int(ij[0])

        j = int(ij[1])

        for k in range(min([i,j]),max([i,j])+1):
            fillPath(k,jumps,100000000)
        
        m = max(jumps[min([i,j]):max([i,j])+1])
            
        print(str(i) + " " + str(j) + " " + str(m))
        ij = input().rstrip().split()
    # f.close()


