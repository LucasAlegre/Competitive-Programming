"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

flag = False

def test(l, row, col):
    
    if row == 4:
        for i in range(col, 5):
            if l[4][i] == 1:
                return
        global flag
        flag = True

    else:

        andar = []
        for i in range(col,5):
            if l[row][i] == 1:
                break
            else:
                andar.append(i)

        for i in range(col,-1,-1):
            if l[row][i] == 1:
                break
            else:
                andar.append(i)

        for j in andar:
            if l[row+1][j] == 0:
                test(l,row+1,j)

from sys import stdin

if __name__ == '__main__':

    n = int(input())
    for _ in range(n):
        l = []
        input() 
        for _ in range(5):
            l.append([int(x) for x in input().split()])
        flag = False
        test(l,0,0)
        if flag:
            print('COPS')
        else:
            print('ROBBERS')

