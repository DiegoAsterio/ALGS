#!/bin/python3

import math
import os
import random
import re
import sys

def getPayment(p):
    total = sum(p)
    n = len(p)
    q = total/n
    q = math.floor(q*100)/100
    ret = 0.0
    for pp in p:
        if pp <= q:
            ret += q - pp
    return ret

if __name__ == '__main__':
    inputFile = "./brianfry.in"
    with open(inputFile) as f:
        for line in f:
            n= int(line.rstrip())
            if n == 0:
                break
            vp = []
            for _ in range(n):
                p = float(f.readline().rstrip())
                vp.append(p)
            # getPayment(vp)
            print("$"+str(getPayment(vp)))
