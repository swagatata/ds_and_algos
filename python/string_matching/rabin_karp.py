import sys
import math
import os
from subprocess import Popen

def rabin_karp(p, t):
    diff_len = len(p) > len(t)
    if diff_len:
        return -1
        
    for i in range(diff_len + 1):
        if hash(p) == hash(t[i:i+diff_len]):
            if (p == t[i:i+diff_len])
                return i

def main():
    rf = open('string_matching_input')
    T = int(rf.readline())
        
    for i in range(T):
        p = rf.readline().strip()
        t = rf.readline().strip()
        print p[rabin_karp(p,t):]

if __name__ == '__main__':
    main()
