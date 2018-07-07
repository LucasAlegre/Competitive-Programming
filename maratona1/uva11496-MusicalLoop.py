"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin

if __name__ == '__main__':

    while True:

        n = int(stdin.readline())
        if n == 0:
            break   
        l = [int(x) for x in stdin.readline().split()]
        c=0
        for i in range(n):
            if l[i] > l[i-1]:
                if i == n-1:
                    if l[i] > l[0]:
                        c+=1
                else:
                    if l[i] > l[i+1]:
                        c+=1
             
            elif l[i] < l[i-1]:
                if i == n-1:
                    if l[i] < l[0]:
                        c+=1
                else:
                    if l[i] < l[i+1]:
                        c+=1
        print(c)
