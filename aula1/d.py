if __name__ == '__main__':
    for _ in range(int(input())):
        x =[int(x) for x in input().split()]
        x.remove(max(x))
        x.remove(min(x))
        print('Case '+ str(_+1) + ': ' +str(x[0]))

