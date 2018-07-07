"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin
import itertools


if __name__ == '__main__':

    for line in stdin:
        n, k = [int(x) for x in line.split()]
        l = [int(x) for x in input().split()]
        medias = []
        for comb in itertools.combinations(l, 3):
            medias.append(sum(comb)/3)
        medias = sorted(medias, reverse=True)
        print('%.1f' % medias[k-1])
