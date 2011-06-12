import sys
import math
import os
from subprocess import Popen

def make_pie(pattern):
    pie = [0] * (len(pattern) + 1)
    pie[0] = 0

    for i in range(1, len(pattern)):
        matched = pie[i-1]
        while True:
            if pattern[i] == pattern[matched]:
                pie[i] = matched+1
                break
            else:
                if matched == 0:
                    pie[i] == 0
                    break
                    
            matched = pie[matched]    
    return pie

def kmp(text, pattern):
    pie = make_pie(pattern)
    print pie
    n = len(text)
    m = len(pattern)

    indices = []

    i = 0 
    j = 0
    while(True):
        if (i >= n):
            return indices

        if (text[i] == pattern[j]):
            if (j == m-1):
                indices.append(i - m + 1)
                i += 1
                j -= pie[j-1]
                continue
            i += 1
            j += 1
        else:
            if (j == 0):
                i += 1
                continue
            j = pie[j-1]

def main():
    rf = open('string_matching_input')
    T = int(rf.readline())
        
    for i in range(T):
        p = rf.readline().strip()
        t = rf.readline().strip()
        print kmp(t, p)

if __name__ == '__main__':
    main()
